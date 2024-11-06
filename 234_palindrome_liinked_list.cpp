#include <iostream>
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
    ListNode *rev(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while (cur)
        {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode *head)
    {
        int length = 0;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *high = rev(slow->next);
        ListNode *low = head;
        while (high)
        {
            if (high->val != low->val)
                return false;
            high = high->next;
            low = low->next;
        }
        return true;
    }
};
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);
    Solution s;
    cout << s.isPalindrome(head);
    return 0;
}