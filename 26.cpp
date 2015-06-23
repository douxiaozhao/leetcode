#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums)
{
    int length = nums.size();
    if( length == 0 )
        return 0;

    int len = 1;
    for( int i = 1; i < length; ++i )
    {
        if( nums[i] != nums[len-1] )
            nums[len++] = nums[i];
    }

    while( length > len )
    {
        --length;
        nums.pop_back();
    }

    return len;
}
