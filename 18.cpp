/*
 * =====================================================================================
 *
 *       Filename:  18.cpp
 *
 *    Description:  4Sum
 *
 *        Version:  1.0
 *        Created:  04/28/15 14:22:53
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

vector< vector<int> > fourSum(vector<int> &num, int target)
{
	vector<vector<int> > ret;

	if (num.size() == 0) return ret;

	sort(num.begin(), num.end());

	for (size_t a = 0; a < num.size(); ++a)
	{
		if (a != 0 && num[a] == num[a - 1])
		{
			continue;
		}

		for (size_t b = a + 1; b < num.size(); ++b)
		{
			if (b != a + 1 && num[b] == num[b - 1])
			{
				continue;
			}

			size_t c = b + 1;
			size_t d = num.size() - 1;

			while (c < d)
			{
				const int sum = num[a] + num[b] + num[c] + num[d];

				if (sum > target)
				{
					--d;
				}
				else if (sum < target)
				{
					++c;
				}
				else if (c != b + 1 && num[c] == num[c - 1])
				{
					++c;
				}
				else if (d != num.size() - 1 && num[d] == num[d + 1])
				{
					--d;
				}
				else
				{
					vector<int> result;

					result.push_back(num[a]);
					result.push_back(num[b]);
					result.push_back(num[c]);
					result.push_back(num[d]);

					ret.push_back(result);

					++c;
					--d;
				}
			}
		}
	}

	return ret;
}

int main()
{
	vector<int> num;
	/*  
	num.push_back(-2);
	num.push_back(-1);
	num.push_back(2);
	num.push_back(1);
	*/
	num.push_back(0);
	num.push_back(0);
	num.push_back(0);
	num.push_back(0);


    vector< vector<int> > ans = fourSum(num, 0);

	for(vector< vector<int> >::iterator it = ans.begin(); it != ans.end(); ++it)
	{
		for(vector<int>::iterator it2 = it->begin(); it2 != it->end(); ++it2)
			cout << *it2 << " ";
		cout << endl;
	}

	return 0;
}
