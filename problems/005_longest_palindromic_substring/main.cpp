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

// 官方的中心法好一些
std::pair<int, int> expandAroundCenter(const std::string &s, int left, int right)
{
    while (left >= 0 && right < s.size() && s[left] == s[right])
    {
        --left;
        ++right;
    }
    return {left + 1, right - 1};
}

std::string longestPalindrome2(std::string s)
{
    int start = 0, end = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        auto [left1, right1] = expandAroundCenter(s, i, i);
        auto [left2, right2] = expandAroundCenter(s, i, i + 1); // 阿哲
        if (right1 - left1 > end - start)
        {
            start = left1;
            end = right1;
        }
        if (right2 - left2 > end - start)
        {
            start = left2;
            end = right2;
        }
    }
    return s.substr(start, end - start + 1);
}

// 官方的动态规划,但是又没有完全的动态规划

std::string longestPalindrome3(std::string s)
{

    int n = s.size();
    if (n < 2)
    {
        return s;
    }

    int maxLen = 1;
    int begin = 0;
    // dp[i][j] 表示 s[i..j] 是否是回文串
    std::vector<std::vector<int>> dp(n, std::vector<int>(n));
    // 初始化：所有长度为 1 的子串都是回文串
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = true;
    }
    // 递推开始
    // 先枚举子串长度
    for (int L = 2; L <= n; L++)
    {
        // 枚举左边界，左边界的上限设置可以宽松一些
        for (int i = 0; i < n; i++)
        {
            // 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
            int j = L + i - 1;
            // 如果右边界越界，就可以退出当前循环
            if (j >= n)
            {
                break;
            }

            if (s[i] != s[j])
            {
                dp[i][j] = false;
            }
            else
            {
                if (j - i < 3)
                {
                    dp[i][j] = true;
                }
                else
                {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }

            // 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
            if (dp[i][j] && j - i + 1 > maxLen)
            {
                maxLen = j - i + 1;
                begin = i;
            }
        }
    }
    return s.substr(begin, maxLen);
}

std::string y("babad");

int main(int argc, char const *argv[])
{
    std::cout << longestPalindrome3(y);
    return 0;
}
