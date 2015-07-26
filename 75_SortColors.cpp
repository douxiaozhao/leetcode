#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        int colors[3] = {0, 0, 0};
        int len = nums.size(), k = 0;
        for(int i = 0; i < len; ++i)
            colors[nums[i]]++;
        for(int i = 0; i < 3; ++i)
            for(int j = 0; j < colors[i]; ++j)
                nums[k++] = i;
    }
};
