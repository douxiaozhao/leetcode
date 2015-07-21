#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if(head == NULL)
            return NULL;
        int len = 1;

        ListNode *tail, *ans, *tmp;
        for(tail = head; tail->next != NULL; tail = tail->next, ++len);
        k = k % len;
        int pos = len-k-1;
        if(k == 0 || pos < 0)
            return head;
        for(tmp = head; pos > 0; --pos, tmp = tmp->next);
        ans = tmp->next;

        tmp->next = NULL;
        tail->next = head;

        return ans;
    }
};

int main()
{
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);

    head = s.rotateRight(head, 1);

    while(head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}
