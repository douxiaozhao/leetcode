#include <iostream>
#include <vector>
using namespace std;

void nextPermutation(vector<int>& nums)
{
    vector<int>::iterator left, right;
    left = nums.end();

    do
    {
        --left;
        // notice left 右边的肯定是按照降序排列的
        for(right = nums.end()-1; right != left; --right)
        {
            if(*left < *right)
            {
                // 交换两者
                int temp = *left;
                *left = *right;
                *right = temp;

                // left之后的重新排序
                sort(left+1, nums.end());
                return;
            }
        }
    }while(left != nums.begin());

    sort(nums.begin(), nums.end());
}


int main()
{
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(2);
    nums.push_back(0);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(0);

    nextPermutation(nums);

    for(vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
        cout << *it <<  " ";
    cout << endl;
}
