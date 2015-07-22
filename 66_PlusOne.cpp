#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        vector<int> ans;
        int c = 1, len = digits.size();
        for(int i = len-1; i >= 0; --i)
        {
            c = c + digits[i];
            ans.push_back(c%10);
            c /= 10;
        }
        if(c > 0)
            ans.push_back(c);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
