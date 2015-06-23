/*
 * =====================================================================================
 *
 *       Filename:  21.cpp
 *
 *    Description:  Merge Two Sorted Lists
 *
 *        Version:  1.0
 *        Created:  04/29/15 23:11:13
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	if( l1 == NULL )
		return l2;
	else if(l2 == NULL )
		return l1;

	ListNode* head = new ListNode(0);
	ListNode* p = head;

	while( l1 && l2 )
	{
		if(l1->val < l2->val)
		{
			p->next = l1;
			l1 = l1->next;
		}
		else
		{
			p->next = l2;
			l2 = l2->next;
		}
		p = p->next;
	}

	if(l1)
		p->next = l1;
	else
		p->next = l2;

	p = head->next;
	delete head;

	return p;
}

int main()
{
	return 0;
}
