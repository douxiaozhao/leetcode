#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p)
    {
        ans = false;
        dfs(s, p, 0, 0);
        return ans;
    }

private:
    void dfs(const string& s, const string& p, int x, int y)
    {
        if(ans)
        {
            return;
        }
        if(x == s.size() && y == p.size())
        {
            ans = true;
            return;
        }
        else if(x == s.size() || y == p.size())
        {
            return;
        }

        if(s[x] == p[y] || p[y] == '?')
            dfs(s, p, x+1, y+1);
        else if(p[y] == '*')
        {
            int len = s.size() - x;
            for(int i = 0; i <= len; ++i)
                dfs(s, p, x+i, y+1);
        }
    }

    bool ans;
};


int main()
{
    string s, p;
    Solution solution;
    while(true)
    {
        cin >> s;
        cin >> p;
        cout << solution.isMatch(s, p) << endl;
    }
    return 0;
}
