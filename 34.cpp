#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        vector<int> result;
        result.push_back(getLeft(nums, target));
        result.push_back(getRight(nums, target));
        return result;
    }

private:
    int getLeft(vector<int>& nums, int target)
    {
        int l = 0, r = nums.size()-1;
        while(l < r)
        {
            int m = (l+r)/2;
            if(nums[m] < target)
                l = m+1;
            else if(nums[m] > target)
                r = m-1;
            else
                r = m;
        }
        if(nums[l] == target)
            return l;
        return -1;
    }

    int getRight(vector<int>& nums, int target)
    {
        int l = 0, r = nums.size()-1;
        while(l < r)
        {
            int m = (l+r+1)/2;
            if(nums[m] < target)
                l = m+1;
            else if(nums[m] > target)
                r = m-1;
            else
                l = m;
        }
        if(nums[r] == target)
            return r;
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    nums.push_back(5);
    nums.push_back(7);
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(8);
    nums.push_back(10);

    vector<int> result = s.searchRange(nums, 1);

    for(vector<int>::iterator it = result.begin(); it != result.end(); ++it)
        cout << *it <<  ' ';
    cout << endl;

    return 0;
}
