// Run on (4 X 2000 MHz CPU s)
// Load Average: 1.24, 0.85, 0.37
// ***WARNING*** CPU scaling is enabled, the benchmark real time measurements may be noisy and will incur extra overhead.
// ***WARNING*** Library was built as DEBUG. Timings may be affected.
// -----------------------------------------------------
// Benchmark           Time             CPU   Iterations
// -----------------------------------------------------
// test1           11172 ns        11083 ns        92053
// test2             369 ns          369 ns      1895513
#include <vector>
#include <stack>
#include <cmath>

#include <iostream>

#include "benchmark/benchmark.h"

int reverse(int x)
{
    long t1 = std::abs((long)x);
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
}

int reverse1(int x)
{
    int rev = 0;
    while (x != 0)
    {
        if (rev < INT_MIN / 10 || rev > INT_MAX / 10)
        {
            return 0;
        }
        int digit = x % 10;
        x /= 10;
        rev = rev * 10 + digit;
    }
    return rev;
}

int l = 2147483611;

static void test1(benchmark::State &state)
{
    for (auto _ : state)
    {
        int f = reverse(l);
    }
}
BENCHMARK(test1);

static void test2(benchmark::State &state)
{
    for (auto _ : state)
    {
        int f = reverse1(l);
    }
}
BENCHMARK(test2);

BENCHMARK_MAIN();