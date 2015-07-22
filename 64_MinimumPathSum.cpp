#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid)
    {
        if(grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();

        int f[1000][1000];
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                f[i][j] = 0;
        f[0][0] = grid[0][0];
        for(int i = 1; i < n; ++i)
            f[0][i] = f[0][i-1]+grid[0][i];
        for(int i = 1; i < m; ++i)
            f[i][0] = f[i-1][0]+grid[i][0];

        for(int i = 1; i < m; ++i)
            for(int j = 1; j < n; ++j)
                f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i][j];

        return f[m-1][n-1];
    }
};
