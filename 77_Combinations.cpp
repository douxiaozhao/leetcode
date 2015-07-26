#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k)
    {
        deep(0, 1, n, k);
        return ans;
    }

private:
    void deep(int p, int s, int n, int k)
    {
        if(p == k)
        {
            ans.push_back(record);
            return;
        }

        for(int i = s; n - i + p + 1 >= k && i <= n; ++i)
        {
            record.push_back(i);
            deep(p+1, i+1, n, k);
            record.pop_back();
        }
    }

    vector<int> record;
    vector<vector<int> > ans;
};
