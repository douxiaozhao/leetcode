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

    return false;
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
