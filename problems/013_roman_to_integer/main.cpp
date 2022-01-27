#include <unordered_map>
#include <string>
#include <iostream>

int romanToInt(std::string s)
{
    std::unordered_map<char, int> hashtab = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };

    int ret = 0;
    int n = s.length();
    for (int i = 0; i < n; ++i)
    {
        int value = hashtab[s[i]];
        if (i < n - 1 && value < hashtab[s[i + 1]])
        {
            ret -= value;
        }
        else
        {
            ret += value;
        }
    }
    return ret;
}
