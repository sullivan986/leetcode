// 结果如下
// Run on (4 X 1500 MHz CPU s)
// Load Average: 0.34, 0.22, 0.23
// ***WARNING*** CPU scaling is enabled, the benchmark real time measurements may be noisy and will incur extra overhead.
// ------------------------------------------------------
// Benchmark            Time             CPU   Iterations
// ------------------------------------------------------
// twoSum_hash   12649165 ns     12535814 ns           57
// twoSum_Map    36639330 ns     36563721 ns           18
// twoSum_enum 6259777156 ns   6254493533 ns            1

#include <map>
#include <unordered_map>
#include <vector>

#include "benchmark/benchmark.h"

using namespace std;

// 第一反应就是哈希表，毕竟阿三的课最喜欢讲这玩意儿了
vector<int> twoSum_unordered_map(vector<int> &nums, int target)
{
    unordered_map<int, int> hashtable;
    for (int i = 0; i < nums.size(); ++i)
    {
        auto it = hashtable.contains(target - nums[i]);
        if (it)
        {
            return {hashtable[target - nums[i]], i};
        }
        hashtable[nums[i]] = i;
    }
    return {};
}

// 用红黑树试一试
vector<int> twoSum_map(vector<int> &nums, int target)
{
    map<int, int> map_s;
    for (int i = 0; i < nums.size(); ++i)
    {
        auto it = map_s.contains(target - nums[i]);
        if (it)
        {
            return {map_s[target - nums[i]], i};
        }
        map_s[nums[i]] = i;
    }
    return {};
}

// 暴力枚举在数量级低的时候有优势，大概在一千左右就不行了
vector<int> twoSum_enumeration(vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = 0; j < nums.size(); ++j)
        {
            if (nums[i] + nums[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {};
}

vector<int> getArr()
{
    vector<int> ut;
    ut.reserve(50000);
    for (size_t i = 0; i < 50000; i++) // 针对不同情景，测试该如何完善？ 有时间再看看gtest
    {
        ut.emplace_back(i);
    }
    return ut;
}

// 开始测试
const auto e = getArr();

static void twoSum_hash(benchmark::State &state)
{
    auto e = getArr();
    for (auto _ : state)
    {
        auto c = twoSum_unordered_map(e, 99997);
    }
}
BENCHMARK(twoSum_hash);

static void twoSum_Map(benchmark::State &state)
{
    auto e = getArr();
    for (auto _ : state)
    {
        auto c = twoSum_map(e, 99997);
    }
}
BENCHMARK(twoSum_Map);

static void twoSum_enum(benchmark::State &state)
{
    auto e = getArr();
    for (auto _ : state)
    {
        auto c = twoSum_enumeration(e, 99997);
    }
}
BENCHMARK(twoSum_enum);

BENCHMARK_MAIN();