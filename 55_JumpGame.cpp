#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int len = nums.size();
        bool *flag = new bool[len];
        fill(flag, flag+len, false);
        flag[0] = true;

        for(int i = 0; i < len; ++i)
        {
            if(!flag[i])
                return false;
            if(i+nums[i]+1 >= len)
                break;
            if(flag[i+nums[i]])
                continue;
            fill(flag+i+1, flag+i+nums[i]+1, true);
        }
        return true;
    }
};
