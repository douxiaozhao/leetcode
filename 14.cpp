/*
 * =====================================================================================
 *
 *       Filename:  14.cpp
 *
 *    Description:  Longest Common Prefix
 *
 *        Version:  1.0
 *        Created:  02/08/15 16:19:10
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
#include <vector>
using namespace std;

int min(int x, int y)
{
	if (x < y)
		return x;
	return y;
}

string longestCommonPrefix(vector<string> &strs)
{
	string r = "";
	int len = strs.size(), minLen;
    if(0 == len)
		return r;

	string s = strs[0];
	minLen = s.size();

	for(int i = 1; i < len; i++)
	{
		int l = min(minLen, strs[i].size());
		int j = 0;
		while(j < l && s[j] == strs[i][j])
			j++;
		minLen = j;
	}
	return s.substr(0, minLen);
}
