#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    int search(vector<int>& nums, int target)
    {
        int ans;
        int pivot = getPivot(nums);

        ans = binarySearch(nums, target, 0, pivot);
        if(ans >= 0)
            return ans;
        ans = binarySearch(nums, target, pivot+1, nums.size()-1);
        return ans;
    }

private:
    int getPivot(vector<int>& nums)
    {
        int left = 0, right = nums.size()-1;
        while(left < right-1)
        {
            int m = (left+right)/2;
            if(nums[left] > nums[m])
                right = m;
            else if(nums[m] > nums[right])
                left = m;
            else
                return left;
        }
        return left;
    }

    int binarySearch(vector<int>& nums, int target, int left, int right)
    {
        while(left <= right)
        {
            int m = (left+right)/2;
            if(nums[m] == target)
                return m;
            else if(nums[m] > target)
                right = m - 1;
            else
                left = m + 1;
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    nums.push_back(4);
    /*
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    */

    cout << s.search(nums, 4) << endl;
    return 0;
}
