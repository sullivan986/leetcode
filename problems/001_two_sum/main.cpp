#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum_unordered_map(vector<int> &nums, int target)
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

    vector<int> twoSum_enumeration(vector<int> &nums, int target)
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
    for (size_t i = 0; i < 7; i++)
    {
        cout << i;
    }
    cout << "\n";
    for (size_t i = 0; i < 7; ++i)
    {
        cout << i;
    }
}
