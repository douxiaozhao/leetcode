/*
 * =====================================================================================
 *
 *       Filename:  13.cpp
 *
 *    Description:  Roman to Integer
 *
 *        Version:  1.0
 *        Created:  01/25/15 22:26:35
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
#include <map>
using namespace std;

map<char, int> info;

void init()
{
    info.insert(make_pair('I', 1));
    info.insert(make_pair('V', 5));
    info.insert(make_pair('X', 10));
    info.insert(make_pair('L', 50));
    info.insert(make_pair('C', 100));
    info.insert(make_pair('D', 500));
    info.insert(make_pair('M', 1000));
}

int romanToInt(string s)
{
    int cur = 0, res = 0, len = s.length(); 
	for(int i = len - 1; i >= 0; --i)
	{
		map<char, int>::iterator it = info.find(s.at(i));
		int m = 0;
		if(it != info.end())
			m = it->second;
		if(m >= cur)
			res += m;
		else
			res -= m;
		cur = m;
	}
	return res;
}

int main()
{
	init();
	string s;
	while(true)
	{
		s.clear();
		cin >> s;
		cout << romanToInt(s) << endl;
	}
	return 0;
}
