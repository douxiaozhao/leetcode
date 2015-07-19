#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int ans, sum, len;

        len = nums.size();
        sum = 0;
        ans = nums[0];

        for(int i = 0; i < len; ++i)
        {
            int e = nums[i];
            if(e + sum > 0)
            {
                sum += e;
                ans = max(ans, sum);
            }
            else
                sum = 0;
            ans = max(ans, e);
        }

        return ans;
    }
};
