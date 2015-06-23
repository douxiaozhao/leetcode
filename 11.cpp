/*
 * =====================================================================================
 *
 *       Filename:  11.cpp
 *
 *    Description:  Container With Most Water
 *
 *        Version:  1.0
 *        Created:  01/25/15 16:47:12
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

int maxArea(vector<int> &height)
{
    int l = 0, r = height.size() - 1, maxA = 0;
    while(l < r)
    {
        maxA = max(maxA, min(height[l], height[r]) * (r - l));
        if(height[l] > height[r])
            --r;
        else
            ++l;
    }
    return maxA;
}
