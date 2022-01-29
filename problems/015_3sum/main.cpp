#include <vector>
#include <algorithm>
#include <iostream>
std::vector<std::vector<int>> threeSum1(std::vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> ans;
    // 枚举 a
    for (int first = 0; first < n; ++first)
    {
        // 需要和上一次枚举的数不相同
        if (first > 0 && nums[first] == nums[first - 1])
        {
            continue;
        }
        // c 对应的指针初始指向数组的最右端
        int third = n - 1;
        int target = -nums[first];
        // 枚举 b
        for (int second = first + 1; second < n; ++second)
        {
            // 需要和上一次枚举的数不相同
            if (second > first + 1 && nums[second] == nums[second - 1])
            {
                continue;
            }
            // 需要保证 b 的指针在 c 的指针的左侧
            while (second < third && nums[second] + nums[third] > target)
            {
                --third;
            }
            // 如果指针重合，随着 b 后续的增加
            // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
            if (second == third)
            {
                break;
            }
            if (nums[second] + nums[third] == target)
            {
                ans.push_back({nums[first], nums[second], nums[third]});
            }
        }
    }
    return ans;
}

// 弃之，食答案
std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
{
    int sz = nums.size();
    if (sz < 3)
    {
        return {};
    }
    std::vector<std::vector<int>> ret;
    std::sort(std::begin(nums), std::end(nums));

    if ((int)nums.size() == 3 && nums[0] == nums[1] && nums[1] == nums[2] && nums[2] == 0)
    {
        return {{0, 0, 0}};
    }

    int l;
    int r;

    int temp1;

    int nums1, nums2, nums3;

    for (int32_t i = 0; i < sz - 2; ++i)
    {
        l = i + 1;
        r = sz - 1;
        while (l < r)
        {
            nums1 = nums[i];
            nums2 = nums[l];
            nums3 = nums[r];
            temp1 = nums1 + nums2 + nums3;

            if (nums2 == nums[l + 1] && l + 1 < r)
            {
                ++l;
                continue;
            }
            if (nums3 == nums[r - 1] && r - 1 > l)
            {
                --r;
                continue;
            }

            if (temp1 < 0)
            {
                ++l;
            }
            else if (temp1 > 0)
            {
                --r;
            }
            else
            {
                if (nums[i] == nums[i + 1] && l != i + 1)
                {
                    break;
                }
                else
                {
                    ret.push_back({nums[i], nums[l++], nums[r--]});
                }
            }
        }
    }

    return ret;
}

std::vector<int> a = {1, 1, -2};

int main(int argc, char const *argv[])
{
    auto u = threeSum(a);
    for (size_t i = 0; i < u.size(); i++)
    {
        for (int32_t j = 0; j < 3; ++j)
        {
            std::cout << u[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
