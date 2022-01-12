#include <iostream>
#include <vector>
#include <array>

#include "benchmark/benchmark.h"

const std::array<int, 3> a1 = {0, 2, 1};
const std::array<int, 2> a2 = {6, 7};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// test1: 对位相加法
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *ptr = nullptr;
    ListNode *ln = nullptr;

    int carry = 0;

    while (l1 || l2)
    {
        int n1 = l1 ? l1->val : 0;
        int c = l1->val;
        int n2 = l2 ? l2->val : 0;
        int sum = n1 + n2 + carry;
        if (!ptr)
        {
            ptr = ln = new ListNode(sum % 10);
        }
        else
        {
            ln->next = new ListNode(sum % 10);
            ln = ln->next;
        }
        carry = sum / 10;
        if (l1)
        {
            l1 = l1->next;
        }
        if (l2)
        {
            l2 = l2->next;
        }
    }
    if (carry > 0)
    {
        ln->next = new ListNode(carry);
    }
    return ptr;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *ptr = new ListNode();
}

// 返回一个测试数组
std::vector<ListNode *> init()
{
    std::vector<ListNode *> t;

    ListNode *p1 = nullptr;
    ListNode *p11 = nullptr;
    ListNode *p2 = nullptr;
    ListNode *p22 = nullptr;

    p11 = p1 = new ListNode();
    p22 = p2 = new ListNode();

    for (size_t i = 0; i < a1.size(); i++)
    {
        p1->next = new ListNode();
        p1->val = a1[i];
        p1 = p1->next;
    }
    p1->next = nullptr;

    for (size_t i = 0; i < a2.size(); i++)
    {
        p2->next = new ListNode();
        p2->val = a2[i];
        p2 = p2->next;
    }
    p2->next = nullptr;

    t.emplace_back(p11);
    t.emplace_back(p22);
    return t;
}

// int main()
// {
//     auto v = init();
//     auto r = addTwoNumbers(v[0], v[1]);
//     for (size_t i = 0; i < 3; i++)
//     {
//         std::cout << r->val;
//         r = r->next;
//     }
// }

static void test1(benchmark::State &state)
{
    auto v = init();
    for (auto _ : state)
    {
        auto t = addTwoNumbers(v[1], v[2]);
    }
}
BENCHMARK(test1);