#include <vector>
#include <stack>
#include <cmath>

#include <iostream>

int reverse(int x)
{
    long t1 = x > 0 ? x : -x;
    bool sb = x > 0 ? true : false;

    std::vector<int> ret;

    if (t1 > 9)
    {
        while (t1)
        {
            ret.emplace_back(t1 % 10);
            t1 = t1 / 10;
        }
        int32_t k = ret.size();
        for (auto te : ret)
        {
            t1 += te * std::pow(10, k - 1);
            k--;
        }
        if (t1 >= std::pow(2, 31))
        {
            return 0;
        }

        return (int32_t)sb ? t1 : -t1;
    }
    else
    {
        return x;
    }
    try
    {
        /* code */
    }
    (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

int main(int argc, char const *argv[])
{
    int l = -2147483648;
    std::cout << reverse(l);
    return 0;
}
