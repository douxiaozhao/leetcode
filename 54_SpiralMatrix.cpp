#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix)
    {
        vector<int> ans;
        int row = matrix.size()-1;
        if(row < 0)
            return ans;
        int col = matrix[0].size()-1;
        if(col < 0)
            return ans;

        int len = min(row, col)/2;

        for(int i = 0; i <= len; ++i)
            addCircle(i, row, col, matrix, ans);

        return ans;
    }

private:
    void addCircle(int s, int row, int col, vector<vector<int> >& matrix, vector<int>& ans)
    {
        int left, right, top, bottom;
        left = top = s;
        bottom = row - s;
        right = col - s;

        for(int i = left; i <= right; ++i)
            ans.push_back(matrix[top][i]);
        for(int i = top+1; i <= bottom; ++i)
            ans.push_back(matrix[i][right]);
        for(int i = right-1; i >= left && bottom > top; --i)
            ans.push_back(matrix[bottom][i]);
        for(int i = bottom-1; i > top && right > left; --i)
            ans.push_back(matrix[i][left]);
    }
};
