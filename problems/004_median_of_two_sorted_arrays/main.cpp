#include <vector>
#include <iostream>

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

int main(int argc, char const *argv[])
{
    std::vector<int> v1{1, 2, 3};
    std::vector<int> v2{4, 5, 6};
    std::cout << findMedianSortedArrays(v1, v2);
    return 0;
}
