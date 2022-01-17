#include <string>
#include <vector>
#include <iostream>

std::string longestPalindrome(std::string s)
{
    std::string rt = *s.begin();
    std::string rtt = *s.begin();
    int32_t sz = s.size();
    auto it1 = s.begin() + 1;
    auto it2 = it1;

    while (it1 != it2)
    {
        while (it2 != s.end())
        {
            rt.push_back(*it2);
            if (rt = std::reverse(rt.begin(), rt.end()))
            {
                (int32_t) rt.size() >
            }
        }
    }
    return rtt;
}

int main(int argc, char const *argv[])
{
    std::string u{"123321"};
    std::cout << *u.end();
    return 0;
}
