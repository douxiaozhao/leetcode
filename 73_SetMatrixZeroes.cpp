#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix)
    {
        if(matrix.empty() || matrix[0].empty() || (matrix.size() == 1 && matrix[0].size() == 1))
            return;
        int m = matrix.size();
        int n = matrix[0].size();
        bool rowZero = false, colZero = false;

        for(int i = 0; i < m; ++i)
            if(matrix[i][0] == 0)
            {
                colZero = true;
                break;
            }

        for(int j = 0; j < n; ++j)
            if(matrix[0][j] == 0)
            {
                rowZero = true;
                break;
            }

        for(int i = 1; i < m; ++i)
            for(int j = 1; j < n; ++j)
                if(matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;

        for(int i = 1; i < m; ++i)
            if(matrix[i][0] == 0)
                for(int j = 1; j < n; ++j)
                    matrix[i][j] = 0;

        for(int i = 1; i < n; ++i)
            if(matrix[0][i] == 0)
                for(int j = 1; j < m; ++j)
                    matrix[j][i] = 0;

        if(rowZero)
            for(int i = 0; i < n; ++i)
                matrix[0][i] = 0;

        if(colZero)
            for(int i = 0; i < m; ++i)
                matrix[i][0] = 0;
    }
};
