#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        ListNode *tail = head;
        for (int i = 0; i < k; i++)
        {
            if (tail == nullptr)
            {
                return head;
            }
            tail = tail->next;
        }
        ListNode *newhead = rev(head, tail);
        head->next = reverseKGroup(tail, k);
        return newhead;
    }
    ListNode *rev(ListNode *head, ListNode *tail)
    {
        ListNode *temp = head;
        ListNode *prev = nullptr;
        while (temp != tail)
        {
            ListNode *next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }
};
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution s;
    ListNode *newhead = s.reverseKGroup(head, 2);
    while (newhead != nullptr)
    {
        cout << newhead->val << " ";
        newhead = newhead->next;
    }
    return 0;
}