/*
 * =====================================================================================
 *
 *       Filename:  22.cpp
 *
 *    Description:  Generate Parentheses
 *
 *        Version:  1.0
 *        Created:  05/04/15 23:29:17
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
#include <string>

using namespace std;

char *record;

void deep(int depth, int num, int n, vector<string>& ans)
{
	if(depth == n*2)
	{
		ans.push_back(string(record));
		return;
	}

    // 加入 ' ( '
	if(num+1 <= n*2-depth-1)
	{
		record[depth] = '(';
		deep(depth+1, num+1, n, ans);
	}
    // 加入 ' ) '
	if(num > 0)
	{
		record[depth] = ')';
		deep(depth+1, num-1, n, ans);
	}
}

vector<string> generateParenthesis(int n)
{
	vector<string> ans;

	deep(0, 0, n, ans);

	return ans;
}

int main()
{
    int n;
	while(cin >> n)
	{
	    record = new char[n*2+1];
		memset(record, 0, n*2+1);

		vector<string> ans = generateParenthesis(n);

		delete[] record;

		for(vector<string>::iterator it = ans.begin(); it != ans.end(); ++it)
			cout << *it << endl;
		cout << endl;
	}
	return 0;
}
