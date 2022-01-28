#include <vector>
#include <algorithm>
#include <iostream>

std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
{
    int sz = nums.size();
    if (sz < 3)
    {
        return {};
    }
    std::vector<std::vector<int>> ret;
    std::sort(std::begin(nums), std::end(nums));
    std::vector<int> temp = {nums[0], nums[1], nums[2]};

    int l;
    int r;

    int temp1;

    for (int32_t i = 0; i < sz - 2; ++i)
    {
        l = 1;
        r = sz - 1;
        while (l < r)
        {
            temp1 = nums[i] + nums[l] + nums[r];
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
                ret.push_back({nums[i], nums[l++], nums[r--]});
            }
        }
    }

    return ret;
}

std::vector<int> a = {-1, 0, 1, 2, -1, -4};

int main(int argc, char const *argv[])
{
    auto u = threeSum(a);
    for (size_t i = 0; i < u.size(); i++)
    {
        for (int32_t j = 0; j < 3; ++j)
        {
            std::cout << u[i][j] << " ";
        }
    }

    return 0;
}
