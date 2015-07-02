#include <iostream>
#include <string>
using namespace std;

string getSequence(string s)
{
    string ans;
    char last = s[0];
    char temp[20];
    int count = 1, len = s.size();
    for(int i = 1; i <= len; ++i)
    {
        if(s[i] != last)
        {
            memset(temp, 0, sizeof(temp));
            sprintf(temp, "%d%c", count, last);
            ans.append(temp);
            count = 1;
            last = s[i];
        }
        else
        {
            ++count;
        }
    }
    return ans;
}

string countAndSay(int n)
{
    string ans = "1";
    for(int i = 1; i < n; ++i)
        ans = getSequence(ans);
    return ans;
}

int main()
{
    int n;
    while(cin >> n)
    {
        cout << countAndSay(n) << endl;
    }
    return 0;
}


