/*
 * =====================================================================================
 *
 *       Filename:  15.cpp
 *
 *    Description:  3Sum leetcode 第十五题，寻找 vector 中三个数和为0的所有对
 *
 *        Version:  1.0
 *        Created:  03/20/15 18:08:16
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
#include <algorithm>
using namespace std;

void print( vector< vector<int> > &ret)
{
    for(vector< vector<int> >::iterator it = ret.begin(); it != ret.end(); ++it)
	{
		vector<int> tmp = *it;
	    cout << tmp[0] << " " << tmp[1] << " " << tmp[2] << endl;
	}
}

vector< vector<int> > threeSum(vector<int> &num)
{
    vector< vector<int> > ret;

	// 先对num 进行排序
	sort(num.begin(), num.end());
	int len = num.size();
	vector<int> tmp;

	for(int i = 0; i < len - 2; ++i)
	{
		if(i != 0 && num[i] == num[i-1])
			continue;
		int l = i + 1, r = len - 1, sum = 0 - num[i];
		while(l < r)
		{
			if(sum == num[l] + num[r])
			{
				if(l != i+1 && num[l] == num[l-1])
					++l;
				else if(r != len - 1 && num[r] == num[r+1])
					--r;
				else
				{
					tmp.clear();
					tmp.push_back(num[i]);
					tmp.push_back(num[l]);
					tmp.push_back(num[r]);
					ret.push_back(tmp);
					++l;
					--r;
				}

			}
			else if(sum > num[l] + num[r])
				++l;
			else
				--r;
		}
	}
    print(ret);
	return ret;
}

int main()
{
    vector<int> num;
	num.push_back(-1);
	num.push_back(0);
	num.push_back(1);
	num.push_back(2);
	num.push_back(-1);
	num.push_back(-4);

	threeSum(num);
	return 0;
}
