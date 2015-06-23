#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swqpPairs(ListNode* head)
{
    for(ListNode* it = head; it != NULL && it->next != NULL ; it = it->next->next)
    {
        int temp = it->val;
        it->val = it->next->val;
        it->next->val = temp;
    }
    return head;
}
