// Run on (4 X 1500 MHz CPU s)
// Load Average: 0.45, 0.44, 0.24
// ***WARNING*** CPU scaling is enabled, the benchmark real time measurements may be noisy and will incur extra overhead.
// ***WARNING*** Library was built as DEBUG. Timings may be affected.
// -----------------------------------------------------
// Benchmark           Time             CPU   Iterations
// -----------------------------------------------------
// test1           12972 ns        12919 ns        54166
// test2            7234 ns         7143 ns        97790

#include <iostream>
#include <string>
#include <vector>

#include "benchmark/benchmark.h"

// 简单的简单方法
std::string convert(std::string s, int numRows)
{
    if (numRows == 1)
        return s;

    std::vector<std::string> rows(std::min(numRows, int(s.size())));
    int curRow = 0;
    bool goingDown = false;

    for (char c : s)
    {
        rows[curRow] += c;
        if (curRow == 0 || curRow == numRows - 1)
            goingDown = !goingDown;
        curRow += goingDown ? 1 : -1;
    }

    std::string ret;
    for (std::string row : rows)
        ret += row;
    return ret;
}

//
std::string convert1(std::string s, int numRows)
{

    if (numRows == 1)
        return s;

    std::string ret;
    int n = s.size();
    int cycleLen = 2 * numRows - 2;

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j + i < n; j += cycleLen)
        {
            ret += s[j + i];
            if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
                ret += s[j + cycleLen - i];
        }
    }
    return ret;
}

std::string up = {"PAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRING"};
int num = 4;

static void test1(benchmark::State &state)
{
    for (auto _ : state)
    {
        auto u = convert(up, num);
    }
}
BENCHMARK(test1);

static void test2(benchmark::State &state)
{
    for (auto _ : state)
    {
        auto u = convert1(up, num);
    }
}
BENCHMARK(test2);

BENCHMARK_MAIN();