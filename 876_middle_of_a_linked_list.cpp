/**
 * Definition for singly-linked list.
 */
#include <bits/stdc++.h>
using namespace std;
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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *temp = head;
        int length = 0;
        while (temp)
        {
            length++;
            temp = temp->next;
        }
        temp = head;
        // if(length==1){
        //     return head;
        // }
        int mid_index = (length / 2);
        while (mid_index--)
        {
            temp = temp->next;
        }
        return temp;
    }
};
int main()
{
    Solution sol;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    ListNode *middle = sol.middleNode(head);
    while (middle)
    {
        cout << middle->val << " ";
        middle = middle->next;
    }
    return 0;
}