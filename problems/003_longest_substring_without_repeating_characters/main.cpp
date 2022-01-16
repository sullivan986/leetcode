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
// 错误示范
// int lengthOfLongestSubstring(std::string s)
// {
//     if (str.size() == 0)
//     {
//         return 0;
//     }
//
//     auto it = s.begin();
//     std::string::iterator b;
//     int u, u1 = 1;
//     for (size_t i = 0; i < s.size(); i++)
//     {
//         u = 1;
//         b = it + 1;
//         while (*b != *it && it != s.end() - 1)
//         {
//
//             if (b == s.end())
//             {
//                 u = 0;
//                 break;
//             }
//
//             b++;
//             u++;
//         }
//         if (u > u1)
//         {
//             u1 = u;
//         }
//
//         it++;
//     }
//     return u1;
// }

// 官方用哈希集合算，感觉慢了
int lengthOfLongestSubstring(std::string s)
{
    std::unordered_set<char> occ;
    int n = s.size();
    // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
    int rk = -1, ans = 0;
    // 枚举左指针的位置，初始值隐性地表示为 -1
    for (int i = 0; i < n; ++i)
    {
        if (i != 0)
        {
            // 左指针向右移动一格，移除一个字符
            occ.erase(s[i - 1]);
        }
        while (rk + 1 < n && !occ.count(s[rk + 1]))
        {
            // 不断地移动右指针
            occ.insert(s[rk + 1]);
            ++rk;
        }
        // 第 i 到 rk 个字符是一个极长的无重复字符子串
        ans = std::max(ans, rk - i + 1);
    }
    return ans;
}

int lengthOfLongestSubstring2(std::string s)
{
}
// int main(int argc, char const *argv[])
// {
//     int u = lengthOfLongestSubstring(str);
//     std::cout << u;
//     return 0;
// }
