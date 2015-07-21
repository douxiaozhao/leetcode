#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n)
    {
        // 初始化
        vector<vector<int> > ans;
        vector<int> tmp(n, 0);
        for(int i = 0; i < n; ++i)
            ans.push_back(tmp);

        e = 1;
        for(int i = 0; i <= (n-1)/2; ++i)
            addCircle(i, n, ans);

        return ans;
    }

private:
    void addCircle(int s, int n, vector<vector<int> >& ans)
    {
        int left, right, top, bottom;
        left = top = s;
        bottom = n-1-s;
        right = n-1-s;

        for(int i = left; i <= right; ++i)
            ans[top][i] = e++;
        for(int i = top+1; i <= bottom; ++i)
            ans[i][right] = e++;
        for(int i = right-1; i >= left && bottom > top; --i)
            ans[bottom][i] = e++;
        for(int i = bottom-1; i > top && right > left; --i)
            ans[i][left] = e++;
    }

    int e;
};

int main()
{
    Solution s;
    int n;

    while(true)
    {
        cin >> n;
        vector<vector<int> > ans = s.generateMatrix(n);
        for(vector<vector<int> >::iterator rit = ans.begin(); rit != ans.end(); ++rit)
        {
            for(vector<int>::iterator cit = rit->begin(); cit != rit->end(); ++cit)
                cout << *cit << " ";
            cout << endl;
        }
    }
    return 0;
}

