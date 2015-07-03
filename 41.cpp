#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    int firstMissingPositive(vector<int>& nums)
    {
        int len = nums.size();
        for(int i = 0; i < len; ++i)
        {
            while(nums[i] != i+1)
            {
                if(nums[i] <= 0 || nums[i] > len || nums[i] == nums[nums[i]-1])
                    break;
                /*
                cout << nums[i] << " " << nums[nums[i]-1] << endl;
                int temp = nums[i];
                nums[i] = nums[nums[i]-1];
                nums[nums[i]-1] = temp;
                cout << nums[0] << " " << nums[1] << endl;
                */
                swap(nums[i], nums[nums[i]-1]);
            }
        }

        for(int i = 0; i < len; ++i)
            if(nums[i] != i+1)
                return i+1;
        return len+1;
    }
};

int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(1);

    Solution s;
    cout << s.firstMissingPositive(nums) << endl;
    return 0;
}
