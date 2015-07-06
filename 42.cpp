#include <vector>
#include <iostream>
#include <stack>
using namespace std;

class Solution{
public:
    int trap(vector<int>& height)
    {
        int max = 0, n = height.size(), water = 0; // 最高的柱子,将数组分为两半
        for(int i = 1; i < n; ++i)
            if(height[i] > height[max])
                max = i;

        for(int i = 0, peak = 0; i < max; ++i)
            if(height[i] > peak)
                peak = height[i];
            else
                water += (peak-height[i]);
        for(int i = n-1, peak = 0; i > max; --i)
            if(height[i] > peak)
                peak = height[i];
            else
                water += (peak-height[i]);
        return water;
    }

};
