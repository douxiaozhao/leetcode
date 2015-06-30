#include <iostream>
#include <stack>
using namespace std;

int longestValidParentheses(string s)
{
    int result = 0;
    stack< pair<char, int> > stack;

    int len = s.size();
    int *f = new int[len];
    for(int i = 0; i < len; ++i)
        f[i] = 0;

    for(int i = 0; i < len; i++)
    {
        if(s[i] == '(')
            stack.push(make_pair('(', i));
        else if(!stack.empty())
        {
            int pos = stack.top().second;
            f[i] = i-pos+1;
            if(pos>0 && f[pos-1] > 0)
                f[i] += f[pos-1];
            result = max(result, f[i]);
            stack.pop();
        }
    }

    delete[] f;
    return result;
}

int main()
{
    string s = "()(())";
    cout << longestValidParentheses(s) << endl;
}
