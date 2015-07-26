#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target)
    {
        if(matrix.empty() || matrix[0].empty())
            return false;

        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = n - 1;
        while(i < m && j >= 0)
        {
            if(target == matrix[i][j])
                return true;
            else if(target < matrix[i][j])
                --j;
            else
                ++i;
        }
        /*
        for(int i = 0; i < m; ++i)
        {
            if(matrix[i][0] <= target)
            {
                if(matrix[i][n-1] >= target && binarySearch(matrix[i], target))
                    return true;
            }
            else
                break;
        }
        */
        return false;
    }

private:
    bool binarySearch(vector<int>& nums, int target)
    {
        int l = 0, r = nums.size() - 1, m;
        while(l <= r)
        {
            m = (l+r) / 2;
            if(nums[m] == target)
                return true;
            else if(nums[m] > target)
                r = m - 1;
            else
                l = m + 1;
        }
        return false;
    }
};
