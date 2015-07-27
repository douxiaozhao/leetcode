#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> >& board, string word)
    {
        if(word.empty())
            return true;
        if(board.empty() || board[0].empty())
            return false;

        m = board.size();
        n = board[0].size();

        vector<vector<bool> > record(m, vector<bool>(n, false));

        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                //if(board[i][j] == word[0])
                if(deep(0, i, j, board, word, record))
                    return true;

        return false;
    }

private:
    bool deep(int p, int x, int y, vector<vector<char> >& board, const string& word, vector<vector<bool> >&record)
    {
        if(p == word.size())
            return true;

        if(x < 0 || y < 0 || x >= m || y >= n || record[x][y] || board[x][y] != word[p])
            return false;

        record[x][y] = true;
        bool ret = deep(p+1, x-1, y, board, word, record) || deep(p+1, x+1, y, board, word, record) || deep(p+1, x, y-1, board, word, record) || deep(p+1, x, y+1, board, word, record);
        record[x][y] = false;

        return ret;
    }

    int m, n;
};
