/*
 * =====================================================================================
 *
 *       Filename:  19.cpp
 *
 *    Description:  Remove Nth Node From End of List
 *
 *        Version:  1.0
 *        Created:  04/29/15 16:54:34
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

ListNode * removeNthFromEnd(ListNode* head, int n)
{
	if(head == NULL)
		return NULL;

	ListNode *left, *right, *tmp;
	left = right = head;
	for(int i = 0; i < n; ++i)
		right = right->next;

	if(right == NULL)
	{
		tmp = head->next;
		delete head;
		return tmp;
	}

	while(right != NULL )
	{
		right = right->next;
		if( !right )
		{
			tmp = left->next;
			left->next = tmp->next;
			delete tmp;
			break;
		}
		left = left->next;
	}
	return head;
}


int main()
{
    return 0;
}
