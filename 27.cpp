#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val)
{
    int length = nums.size();
    int len = 0;
    for(int i = 0; i < length; ++i)
    {
        if(nums[i] != val)
            nums[len++] = nums[i];
    }

    while( length > len )
    {
        --length;
        nums.pop_back();
    }
    return len;
}
