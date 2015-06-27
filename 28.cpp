/*
 * Implement strStr()
 */

#include <iostream>
#include <string>
using namespace std;

int string_find(const string &haystack, const string &needle)
{
    return haystack.find(needle);
}

void getNext(const string& needle, int *next)
{
    int len = needle.size();
    next[0] = -1;
    int k = -1;
    int j = 0;
    while( j < len-1)
    {
        if(k == -1 || needle[j] == needle[k])
        {
            ++k;
            ++j;
            if(needle[j] != needle[k])
                next[j] = k;
            else
                next[j] = next[k];
        }
        else
        {
            k = next[k];
        }
    }
}

int kmp(const string& haystack, const string& needle)
{
    int hLen = haystack.size();
    int nLen = needle.size();
    int i = 0, j = 0;

    int *next = new int[nLen];
    getNext(needle, next);

    while(i < hLen && j < nLen)
    {
        if(j== -1 || haystack[i] == needle[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
        }
    }
    if(j == nLen)
        return i - j;
    return -1;
}

int strStr(string haystack, string needle)
{
    return kmp(haystack, needle);
}

int main()
{
    string h, n;
    while(true)
    {
        cin >> h;
        cin >>n;
        cout << strStr(h, n) << endl;
    }
    return 0;
}
