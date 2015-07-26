#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums)
    {
        len = nums.size();
        sort(nums.begin(), nums.end());
        deep(0, nums);
        return ans;
    }

private:

    void deep(int s, vector<int>& nums)
    {
        if(s == len)
        {
            ans.push_back(record);
            return;
        }
        deep(s+1, nums);
        record.push_back(nums[s]);
        deep(s+1, nums);
        record.pop_back();
    }

    int len;
    vector<int> record;
    vector<vector<int> > ans;
};

int main()
{
    Solution s;
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(1);
    nums.push_back(0);
    vector<vector<int> > ans = s.subsets(nums);
    for(vector<vector<int> >::iterator it = ans.begin(); it != ans.end(); ++it)
    {
        for(vector<int>::iterator p = it->begin(); p != it->end(); ++p)
            cout << *p << " ";
        cout << endl;
    }
    return 0;
}
