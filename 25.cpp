#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseKGroup(ListNode* head, int k)
{
    int *temp = new int[k];
    ListNode* t = head;

    while(t)
    {
        ListNode *p = t;
        for( int i = 0; i < k; ++i )
        {
            if( p != NULL )
                temp[i] = p->val;
            else
                return head;
            p = p->next;
        }

        for( int i = 0; i < k; ++i )
        {
            t->val = temp[k-i-1];
            t = t->next;
        }
    }

    return head;
}
