/*
 * =====================================================================================
 *
 *       Filename:  RegularExpressionNatching.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  01/25/15 12:53:15
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (),
 *   Organization:
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
using namespace std;

bool isMatch(const char *s, const char *p)
{
    if(*p == '\0')
        return *s == '\0';

    //next char is not '*', then must match current character
    if(*(p+1) != '*')
    {
        if(*p == *s || (*p == '.' && *s != '\0'))
            return isMatch(s+1, p+1);
        else
            return false;
    }
    else
    {
        while(*p == *s || (*p == '.' && *s != '\0'))
        {
            if(isMatch(s, p+2))
                return true;
            s++;
        }
        return isMatch(s, p+2);
    }
}

int main()
{
    string s, p;
    while(true)
    {
        cin >> s;
        cin >> p;
        cout << isMatch(s.c_str(), p.c_str()) << endl;
    }
    return 0;
}
