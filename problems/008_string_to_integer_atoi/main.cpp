#include <string>
#include <vector>
#include <variant>
#include <algorithm>
#include <unordered_map>

// #include "benchmark/benchmark.h"

// 这个应该是状态机了，表格就不写了
// 对于这题其实状态机不算是一个优秀的解法

class Automaton
{
    std::string state = "start";
    std::unordered_map<std::string, std::vector<std::string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}};

    int get_col(char c)
    {
        if (isspace(c))
            return 0;
        if (c == '+' or c == '-')
            return 1;
        if (isdigit(c))
            return 2;
        return 3;
    }

public:
    int sign = 1;
    long long ans = 0;

    void get(char c)
    {
        state = table[state][get_col(c)];
        if (state == "in_number")
        {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? std::min(ans, (long long)INT32_MAX) : std::min(ans, -(long long)INT32_MAX);
        }
        else if (state == "signed")
            sign = c == '+' ? 1 : -1;
    }
};

int myAtoi(std::string s)
{
    Automaton automaton;
    for (char c : s)
        automaton.get(c);
    return automaton.sign * automaton.ans;
}

// 记得以前一个大佬的文章用 cpp17 里面的 std::variant 做了状态机的题，我试一下 (未完成)
struct Start
{
};
struct Signed
{
};
struct In_number
{
};
struct End
{
};

using State = std::variant<Start, Signed, In_number, End>;

template <class... Ts>
struct overload : Ts...
{
    using Ts::operator()...;
};

template <class... Ts>
overload(Ts...) -> overload<Ts...>;

std::vector<std::string> FindNumbers(const std::string &str)
{
    std::vector<std::string> ret;
    State state = Start{};
    for (size_t i = 0; i < str.length(); ++i)
    {
    }
    return ret;
}

int myAtoi1(std::string s)
{
    enum State
    {
        OTHER,
        NUMBER
    } state = OTHER;

    return 0;
}

auto main() -> int
{
}