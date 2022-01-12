#include <string>
#include <iostream>
#include <unordered_set>

const std::string str("a");

// 第一反应有限状态机？
// -----------------------------------------------------------------
//           输入       不同的字符                  有相同的字符
// -----------------------------------------------------------------
// 状态
// -----------------------------------------------------------------
// 不同的字符           位数加一                    提取位数并且下一个为开头数
// -----------------------------------------------------------------
// 开头数               位数归零                    length = 0

// 算了，暴力枚举法
int lengthOfLongestSubstring(std::string s)
{
    if (str.size() == 0)
    {
        return 0;
    }

    auto it = s.begin();
    std::string::iterator b;
    int u, u1 = 1;
    for (size_t i = 0; i < s.size(); i++)
    {
        u = 1;
        b = it + 1;
        while (*b != *it && it != s.end() - 1)
        {

            if (b == s.end())
            {
                u = 0;
                break;
            }

            b++;
            u++;
        }
        if (u > u1)
        {
            u1 = u;
        }

        it++;
    }
    return u1;
}

int main(int argc, char const *argv[])
{
    int u = lengthOfLongestSubstring(str);
    std::cout << u;
    return 0;
}
