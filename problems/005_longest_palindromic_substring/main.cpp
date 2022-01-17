#include <string>
#include <vector>
#include <iostream>

// 瞎写
std::string longestPalindrome(std::string s)
{
    std::string rt;
    std::string rtt{*s.begin()};
    std::string temp;
    auto it1 = s.begin();
    auto it2 = it1;

    while (it1 != s.end() - 1)
    {
        while (it2 != s.end())
        {
            rt.push_back(*it2);
            for (int32_t i = rt.size() - 1; i >= 0; i--)
            {
                temp.push_back(rt[i]);

                if (rt == temp && rt.size() > rtt.size())
                {
                    rtt = rt;
                }
            }
            temp.clear();

            it2++;
        }
        rt.clear();
        it1++;
        it2 = it1;
    }
    return rtt;
}

// 动态规划解法
std::string longestPalindrome2(std::string s)
{
}

std::string y("babad");

int main(int argc, char const *argv[])
{
    std::cout << longestPalindrome(y);
    return 0;
}
