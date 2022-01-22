#include <vector>

#include "benchmark/benchmark.h"

// 一看就不行，试一试一次出入栈搞定
bool isPalindrome(int x)
{
    if (x < 0)
    {
        return false;
    }

    std::vector<int> vt;
    while (x != 0)
    {
        vt.emplace_back(x % 10);
        x = x / 10;
    }

    int32_t f = vt.size();

    for (size_t i = 0; i < f / 2; i++)
    {
        if (vt[i] != vt[f - i - 1])
        {
            return false;
        }
    }

    return true;
}

bool isPalindrome1(int x)
{
    if (x < 0 || (x % 10 == 0 && x != 0))
    {
        return false;
    }

    int revertedNumber = 0;
    while (x > revertedNumber)
    {
        revertedNumber = revertedNumber * 10 + x % 10;
        x /= 10;
    }

    return x == revertedNumber || x == revertedNumber / 10;
}

static void test1()
{
}