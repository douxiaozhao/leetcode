#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int> > permute(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        len = nums.size();
        flag = new bool[len];
        fill(flag, flag+len, false);

        deep(0, nums);

        delete[] flag;
        return ans;
    }

    void deep(int n, vector<int>& nums)
    {
        if(n >= len)
        {
            ans.push_back(record);
            return;
        }

        for(int i = 0; i < len; ++i)
        {
            if(!flag[i])
            {
                flag[i] = true;
                record.push_back(nums[i]);
                deep(n+1, nums);
                flag[i] = false;
                record.pop_back();
                while(i+1 < len && nums[i] == nums[i+1])
                    ++i;
            }
        }
    }

private:
    vector<vector<int> > ans;
    vector<int> record;
    bool *flag;
    int len;
};


int main()
{
    Solution s;
    vector<int> nums;

    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    vector<vector<int> > ans = s.permute(nums);

    for(vector<vector<int> >::iterator it = ans.begin(); it != ans.end(); ++it)
    {
        for(vector<int>::iterator p = it->begin(); p != it->end(); ++p)
            cout << *p << " ";
        cout << endl;
    }

    cout << "end" << endl;
    return 0;
}
