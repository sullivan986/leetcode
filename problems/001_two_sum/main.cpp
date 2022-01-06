#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    static vector<int> twoSum_unordered_map(vector<int> &nums, int target)
    {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i)
        {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end())
            {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }

    static vector<int> twoSum_enumeration(vector<int> &nums, int target)
    {
        for (int16_t i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }
    }
};

int main(int, char **)
{
    vector<int> e{2, 3, 4, 5, 6};
    auto c = Solution::twoSum_unordered_map(e, 9);
    for (size_t i = 0; i < c.size(); i++)
    {
        cout << e[c[i]] << endl;
    }
}
