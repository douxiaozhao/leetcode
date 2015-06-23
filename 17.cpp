/*
 * =====================================================================================
 *
 *       Filename:  17.cpp
 *
 *    Description:  Letter Combinations of a Phone Nuber
 *
 *        Version:  1.0
 *        Created:  04/28/15 12:08:01
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
#include <map>
#include <string>

using namespace std;

map<int, string> info;
char* record;

void init()
{
	info.insert(make_pair(2, "abc"));
	info.insert(make_pair(3, "def"));
	info.insert(make_pair(4, "ghi"));
	info.insert(make_pair(5, "jkl"));
	info.insert(make_pair(6, "mno"));
	info.insert(make_pair(7, "pqrs"));
	info.insert(make_pair(8, "tuv"));
	info.insert(make_pair(9, "wxyz"));
}

void deep(int pos, int q, const string& digits, vector<string> & ans)
{
	if( pos >= digits.size() )
	{
		if( q > 0 )
		{
			record[q] = '\0';
			ans.push_back(string(record));
		}
		return;
	}
    
	int num = digits.at(pos) - '0';

	map<int, string>::iterator it = info.find(num);

	if(it != info.end() )
	{
		string temp = it->second;
		for(int i = 0; i < temp.size(); i++)
		{
            record[pos] = temp.at(i); 
			deep(pos+1, q+1, digits, ans);
		}
	}
	else
	    deep(pos+1, q, digits, ans);
}

vector<string> letterCombinations(string digits)
{
	init();
	record = new char[digits.size() + 1];

	vector<string> ans ;
	
	deep(0, 0, digits, ans);

	delete[] record;

	return ans;
}


int main()
{
	string digits;

	while( cin >> digits )
	{
		//digits = "";
		vector<string> ans = letterCombinations(digits);
		for(vector<string>::iterator it = ans.begin(); it != ans.end(); ++it)
			cout << *it << endl;
		cout << endl;
	}
}
