// Run on (4 X 2000 MHz CPU s)
// Load Average: 0.71, 0.44, 0.18
// ***WARNING*** CPU scaling is enabled, the benchmark real time measurements may be noisy and will incur extra overhead.
// ***WARNING*** Library was built as DEBUG. Timings may be affected.
// -----------------------------------------------------
// Benchmark           Time             CPU   Iterations
// -----------------------------------------------------
// test1             525 ns          517 ns      1352475
// test2             431 ns          431 ns      1620882

#include <vector>
#include <iostream>

#include "benchmark/benchmark.h"

// 双指针
int maxArea(std::vector<int> &height)
{

    auto itb = height.begin();
    auto ite = height.end() - 1;

    int k = 0;
    int s = height.size() - 1;

    while (ite != itb)
    {
        if (*itb >= *ite)
        {
            k = std::max(*ite * s, k);
            --ite;
        }
        else
        {
            k = std::max(*itb * s, k);
            ++itb;
        }

        --s;
    }
    return k;
}

// 官方双指针
int maxArea1(std::vector<int> &height)
{
    int l = 0, r = height.size() - 1;
    int ans = 0;
    while (l < r)
    {
        int area = std::min(height[l], height[r]) * (r - l);
        ans = std::max(ans, area);
        if (height[l] <= height[r])
        {
            ++l;
        }
        else
        {
            --r;
        }
    }
    return ans;
}

std::vector<int> height = {4, 3, 2, 1, 4};

static void test1(benchmark::State &state)
{
    for (auto _ : state)
    {
        int c = maxArea(height);
    }
}
BENCHMARK(test1);

static void test2(benchmark::State &state)
{
    for (auto _ : state)
    {
        int c = maxArea1(height);
    }
}
BENCHMARK(test2);

BENCHMARK_MAIN();
