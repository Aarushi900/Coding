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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode head;
        // if(list1->val>list2->val){
        //     head->val=list2->val;
        //     list2=list2->next;
        // }
        // else{
        //     head->val=list1->val;
        //     list1=list1->next;
        // }
        ListNode *temp = &head;
        while (list1 && list2)
        {
            if (list1->val > list2->val)
            {
                temp->next = list2;
                list2 = list2->next;
            }
            else
            {
                temp->next = list1;
                list1 = list1->next;
            }
            temp = temp->next;
        }
        if (list1)
        {
            temp->next = list1;
        }
        if (list2)
        {
            temp->next = list2;
        }
        return head.next;
    }
};
int main()
{
    Solution sol;
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);
    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);
    ListNode *merged_list = sol.mergeTwoLists(list1, list2);
    while (merged_list)
    {
        cout << merged_list->val << " ";
        merged_list = merged_list->next;
    }
    return 0;
}