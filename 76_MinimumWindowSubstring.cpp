#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t)
    {
        if(s.empty() || s.size() < t.size())
            return "";

        const static int CSIZE = 256;
        int appeared_count[CSIZE];
        int expected_count[CSIZE];
        fill(appeared_count, appeared_count+CSIZE, 0);
        fill(expected_count, expected_count+CSIZE, 0);

        for(size_t i = 0; i < t.size(); ++i)
            expected_count[t[i]]++;

        int minWidth = INT_MAX, min_start = 0;
        int wnd_start = 0;
        int appeared = 0;

        for(size_t i = 0; i < s.size(); i++)
        {
            if(expected_count[s[i]] > 0)
            {
                appeared_count[s[i]]++;
                if(appeared_count[s[i]] <= expected_count[s[i]])
                    ++appeared;
            }
            if(appeared == t.size())
            {
                while(appeared_count[s[wnd_start]] > expected_count[s[wnd_start]] || expected_count[s[wnd_start]] == 0)
                {
                    appeared_count[s[wnd_start]]--;
                    ++wnd_start;
                }
                if(minWidth > (i-wnd_start+1))
                {
                    minWidth = i - wnd_start + 1;
                    min_start = wnd_start;
                }
            }
        }

        if(minWidth == INT_MAX)
            return "";
        return s.substr(min_start, minWidth);
    }
};

int main()
{
    string s, t;
    Solution so;

    while(true)
    {
        cin >> s;
        cin >> t;
        cout << so.minWindow(s, t) << endl;
    }
}
