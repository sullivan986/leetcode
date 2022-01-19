#include <string>
#include <vector>
#include <iostream>

// 瞎写，笑死，超时了都
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

// 双迭代中心扩散法,但是如果回环是偶数就寄了
std::string longestPalindrome1(std::string s)
{
    std::string rt{*s.begin()};

    int32_t index = 1;
    int32_t tp;
    int32_t sz = s.size();

    while (index != sz - 1)
    {
        tp = 1;
        while (index >= tp && index + tp <= sz - 1)
        {
            if (s[index - tp] == s[index + tp])
            {
                if ((tp * 2 + 1) > (int32_t)rt.size())
                {
                    rt.clear();
                    for (size_t i = index - tp; i <= index + tp; i++)
                    {
                        rt.push_back(s[i]);
                    }
                }
            }

            tp++;
        }
        index++;
    }

    return rt;
}

// 动态规划
std::string longestPalindrome1(std::string s)
{
}

std::string y("cbbc");

int main(int argc, char const *argv[])
{
    std::cout << longestPalindrome1(y);
    return 0;
}
