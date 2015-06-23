/*
 * =====================================================================================
 *
 *       Filename:  20.cpp
 *
 *    Description: 括号匹配 
 *
 *        Version:  1.0
 *        Created:  04/29/15 22:02:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValid(string s)
{
	stack<char> storge;

    if(s.empty())
		return true;

	for(int i = 0; i < s.size(); ++i)
	{
		if(storge.empty())
			storge.push(s.at(i));
		else
		{
			char last = storge.top();
			char c = s.at(i);
			if( (last=='('&&c==')') || (last=='{'&&c=='}') || (last=='['&&c==']') )
				storge.pop();
			else
				storge.push(c);
		}
	}

	return (storge.empty());
}
