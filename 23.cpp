/*
 * =====================================================================================
 *
 *       Filename:  23.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  05/05/15 09:13:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (),
 *   Organization:
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;


struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Heap
{
public:
    Heap(int initSize)
    {
        record = new ListNode*[initSize];
        size = 0;
    }

    ~Heap()
    {
        delete[] record;
    }

    void addElement(ListNode* node)
    {
        if(node)
            record[size++] = node;
    }

    void adjust(int x)
    {
        while(true)
        {
            int m = -1;
            if( x*2+1 < size )
            {
                m = x*2+1;
                if(x*2+2 < size && record[x*2+2]->val < record[m]->val)
                    m = x*2+2;
            }
            if( m != -1 && record[x]->val > record[m]->val)
            {
                ListNode* tmp = record[x];
                record[x] = record[m];
                record[m] = tmp;
                x = m;
            }
            else
            {
                break;
            }
        }
    }

    bool createHeap()
    {
        if( size == 0 )
            return false;
        for(int i = size/2; i>=0; --i)
            adjust(i);
        return true;
    }

    ListNode* getElement()
    {
        ListNode *head = record[0];
        if(head == NULL)
            return NULL;

        if(head->next != NULL)
        {
            record[0] = head->next;
        }
        else
        {
            --size;
            if( size > 0)
                record[0] = record[size];
            else
                record[0] = NULL;
        }
        adjust(0);
        return head;
    }

private:
    ListNode** record;
    int size;
};

ListNode* mergeKLists(vector<ListNode*>& lists)
{
    Heap *heap = new Heap(lists.size());

    for(vector<ListNode*>::iterator it = lists.begin(); it != lists.end(); ++it)
        heap->addElement(*it);
    if (!heap->createHeap())
    {
        delete heap;
        return NULL;
    }

    ListNode* head = heap->getElement();
    for(ListNode* tmp = head; tmp != NULL; tmp = tmp->next)
        tmp->next = heap->getElement();

    delete heap;
    return head;
}


int main()
{
    vector<ListNode*> lists;
    lists.push_back(NULL);
    lists.push_back(NULL);

    ListNode *head = mergeKLists(lists);

    return 0;
}
