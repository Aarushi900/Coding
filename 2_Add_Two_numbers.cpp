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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int sum = l1->val + l2->val;
        int carry = sum / 10;
        ListNode *ans = new ListNode(sum % 10); // Initialize the result list with the first node
        ListNode *temp = ans;
        l1 = l1->next;
        l2 = l2->next;

        while (l1 && l2)
        {
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            temp->next = new ListNode(sum % 10);
            temp = temp->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1)
        { // If l1 is longer
            int sum = l1->val + carry;
            carry = sum / 10;
            temp->next = new ListNode(sum % 10);
            temp = temp->next;
            l1 = l1->next;
        }

        while (l2)
        { // If l2 is longer
            int sum = l2->val + carry;
            carry = sum / 10;
            temp->next = new ListNode(sum % 10);
            temp = temp->next;
            l2 = l2->next;
        }

        if (carry)
        { // If there's a leftover carry
            temp->next = new ListNode(carry);
        }

        return ans;
    }
};
int main()
{
    Solution sol;
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    ListNode *ans = sol.addTwoNumbers(l1, l2);
    while (ans)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }
    return 0;
}