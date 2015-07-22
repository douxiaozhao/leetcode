#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid)
    {
        if(obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1)
            return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        int f[100][100];
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                f[i][j] = 0;
        f[0][0] = 1;
        for(int i = 1; i < n && obstacleGrid[0][i] == 0; ++i)
                f[0][i] = 1;
        for(int i = 1; i < m && obstacleGrid[i][0] == 0; ++i)
                f[i][0] = 1;

        for(int i = 1; i < m; ++i)
            for(int j = 1; j < n; ++j)
                if(obstacleGrid[i][j] == 0)
                    f[i][j] = f[i-1][j] + f[i][j-1];
                else
                    f[i][j] = 0;

        return f[m-1][n-1];
    }
};
