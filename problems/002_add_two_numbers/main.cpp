// #include "benchmark/benchmark.h"

#include <iostream>
#include <vector>

const int a1[3] = {0, 2, 1};
const int a2[2] = {6, 7};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    int carry = 0;
    while (l1 || l2)
    {
        int n1 = l1 ? l1->val : 0;
        int c = l1->val;
        int n2 = l2 ? l2->val : 0;
        int sum = n1 + n2 + carry;
        if (!head)
        {
            head = tail = new ListNode(sum % 10);
        }
        else
        {
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
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
        tail->next = new ListNode(carry);
    }
    return head;
}

std::vector<ListNode *> init()
{
    std::vector<ListNode *> t;
    ListNode L1, L2;
    ListNode *p1 = &L1, *p2 = &L2;
    for (size_t i = 0; i < 3; i++)
    {
        p1->next = new ListNode;
        p1->val = a1[i];
        p1 = p1->next;
    }
    p1->next = nullptr;
    p1 = &L1;

    for (size_t i = 0; i < 2; i++)
    {
        p2->next = new ListNode;
        p2->val = a2[i];
        p2 = p2->next;
    }
    p2->next = nullptr;
    p2 = &L2;

    t.emplace_back(p1, p2);
    return t;
}

int main()
{
    auto c = init();
    auto r = addTwoNumbers(c[0], c[1]);
    for (size_t i = 0; i < 3; i++)
    {
        std::cout << r->val;
        r = r->next;
    }
}