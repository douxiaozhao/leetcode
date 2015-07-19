#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n)
    {
        init(n);
        deep(0, n);
        destroy();
        return ans;
    }

private:
    void deep(int pos, int n)
    {
        if(pos == n)
        {
            vector<string> tmp;
            for(int i = 0; i < n; ++i)
            {
                board[record[i]] = 'Q';
                tmp.push_back(string(board));
                board[record[i]] = '.';
            }
            ans.push_back(tmp);
            return;
        }

        for(int i = 0; i < n; ++i)
        {
            int leftPos = getLeft(pos, i, n);
            int rightPos = getRight(pos, i, n);
            if(!col[i] && !left[leftPos] && !right[rightPos])
            {
                col[i] = true;
                left[leftPos] = true;
                right[rightPos] = true;
                record[pos] = i;
                deep(pos+1, n);
                col[i] = false;
                left[leftPos] = false;
                right[rightPos] = false;
            }
        }
    }

    int getLeft(int row, int col, int n)
    {
        return (row-col+n-1);
    }

    int getRight(int row, int col, int n)
    {
        return (row+col);
    }

    void init(int n)
    {
        col = new bool[n];
        left = new bool[(n-1)*2];
        right = new bool[(n-1)*2];
        record = new int[n];
        board = new char[n+1];
        fill(board, board+n, '.');
        board[n] = 0;
        fill(col, col+n, false);
        fill(left, left+(n-1)*2, false);
        fill(right, right+(n-1)*2, false);
    }
    void destroy()
    {
        delete[] col;
        delete[] left;
        delete[] right;
        delete[] record;
        delete[] board;
    }

private:
    bool *col;
    bool *left;
    bool *right;
    int *record;
    char *board;
    vector<vector<string> > ans;
};

int main()
{
    int n;
    while(1)
    {
        Solution s;
        cin >> n;
        vector<vector<string> > ans = s.solveNQueens(n);
        for(vector<vector<string> >::iterator it = ans.begin(); it!= ans.end(); ++it)
        {
            for(vector<string>::iterator sit = it->begin(); sit != it->end(); ++sit)
                cout << *sit << endl;
            cout << endl;
        }
    }
    return 0;
}
