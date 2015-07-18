#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int jump(vector<int>& nums)
    {
        int len = nums.size();
        record = new int[len];
        fill(record, record+len, -1);
        record[0] = 0;

        for(int i = 0; i < len; ++i)
        {
            int e = nums[i];
            for(int j = 1; j <= e && i+j < len; ++j)
            {
                if(record[i+j] == -1 || (record[i] + 1 < record[i+j]))
                    record[i+j] = record[i] + 1;
                else if(i+e <= i+j+nums[i+j])  // 这是一个优化步骤，i+j 位置 比 i位置更优，且能更新更远，i已经没有用啦
                    break;
            }
        }

        int ans = record[len-1];
        delete[] record;
        return ans;
    }

private:
    int *record;
};


int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(4);

    Solution s;
    cout << s.jump(nums) << endl;

    return 0;
}
