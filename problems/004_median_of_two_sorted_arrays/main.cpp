#include <vector>
#include <iostream>

#include "benchmark/benchmark.h"

// Run on (4 X 1500 MHz CPU s)
// Load Average: 0.49, 0.30, 0.12
// ***WARNING*** CPU scaling is enabled, the benchmark real time measurements may be noisy and will incur extra overhead.
// ***WARNING*** Library was built as DEBUG. Timings may be affected.
// ------------------------------------------------------------
// Benchmark                  Time             CPU   Iterations
// ------------------------------------------------------------
// test_add_and_sort       2852 ns         2851 ns       245769
// test_dichotomy           233 ns          233 ns      3002306

// 瞎写的 肯定没有达到 O(log(m+n))
double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
{
    std::vector<int> v;
    v.insert(v.end(), nums1.begin(), nums1.end());
    v.insert(v.end(), nums2.begin(), nums2.end());
    std::sort(v.begin(), v.end());
    int32_t s = v.size();
    if (s == 0)
    {
        return 0;
    }
    if (s % 2 == 0)
    {
        double a = v[(s / 2) - 1];
        double b = v[s / 2];
        return (a + b) / 2;
    }
    else
    {
        return (double)v[s / 2];
    }
}

// 官方二分法
int getKthElement(const std::vector<int> &nums1, const std::vector<int> &nums2, int k)
{
    /* 主要思路：要找到第 k (k>1) 小的元素，那么就取 pivot1 = nums1[k/2-1] 和 pivot2 = nums2[k/2-1] 进行比较
     * 这里的 "/" 表示整除
     * nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
     * nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
     * 取 pivot = min(pivot1, pivot2)，两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
     * 这样 pivot 本身最大也只能是第 k-1 小的元素
     * 如果 pivot = pivot1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums1 数组
     * 如果 pivot = pivot2，那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums2 数组
     * 由于我们 "删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k 的值，减去删除的数的个数
     */

    int m = nums1.size();
    int n = nums2.size();
    int index1 = 0, index2 = 0;

    while (true)
    {
        // 边界情况
        if (index1 == m)
        {
            return nums2[index2 + k - 1];
        }
        if (index2 == n)
        {
            return nums1[index1 + k - 1];
        }
        if (k == 1)
        {
            return std::min(nums1[index1], nums2[index2]);
        }

        // 正常情况
        int newIndex1 = std::min(index1 + k / 2 - 1, m - 1);
        int newIndex2 = std::min(index2 + k / 2 - 1, n - 1);
        int pivot1 = nums1[newIndex1];
        int pivot2 = nums2[newIndex2];
        if (pivot1 <= pivot2)
        {
            k -= newIndex1 - index1 + 1;
            index1 = newIndex1 + 1;
        }
        else
        {
            k -= newIndex2 - index2 + 1;
            index2 = newIndex2 + 1;
        }
    }
}

double findMedianSortedArrays1(std::vector<int> &nums1, std::vector<int> &nums2)
{
    int totalLength = nums1.size() + nums2.size();
    if (totalLength % 2 == 1)
    {
        return getKthElement(nums1, nums2, (totalLength + 1) / 2);
    }
    else
    {
        return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
    }
}

std::vector<int> v1{1, 2, 3};
std::vector<int> v2{4, 5, 6};

static void test_add_and_sort(benchmark::State &state)
{
    for (auto _ : state)
    {
        auto c = findMedianSortedArrays(v1, v2);
    }
}
BENCHMARK(test_add_and_sort);

static void test_dichotomy(benchmark::State &state)
{
    for (auto _ : state)
    {
        auto c = findMedianSortedArrays1(v1, v2);
    }
}
BENCHMARK(test_dichotomy);