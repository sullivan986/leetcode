#include <iostream>
#include <vector>

// 真不会
bool isMatch(std::string s, std::string p)
{
    int m = s.size();
    int n = p.size();

    auto matches = [&](int i, int j)
    {
        if (i == 0)
        {
            return false;
        }
        if (p[j - 1] == '.')
        {
            return true;
        }
        return s[i - 1] == p[j - 1];
    };

    std::vector<std::vector<int>> f(m + 1, std::vector<int>(n + 1));
    f[0][0] = true;
    for (int i = 0; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (p[j - 1] == '*')
            {
                f[i][j] |= f[i][j - 2];
                if (matches(i, j - 1))
                {
                    f[i][j] |= f[i - 1][j];
                }
            }
            else
            {
                if (matches(i, j))
                {
                    f[i][j] |= f[i - 1][j - 1];
                }
            }
        }
    }
    return f[m][n];
}

int main(int argc, char const *argv[])
{
    std::cout << isMatch("ab", ".*");
}