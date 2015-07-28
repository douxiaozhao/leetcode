#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int len = nums.size(), left, right;
        if(len < 3)
            return len;

        for(left = 1, right = 2; right < len; ++right)
        {
            if(nums[right] != nums[left] || nums[right] != nums[left-1])
                nums[++left] = nums[right];
        }
        nums.erase(nums.begin()+left+1, nums.end());

        return nums.size();
    }
};
