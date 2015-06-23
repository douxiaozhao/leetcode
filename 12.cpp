/*
 * =====================================================================================
 *
 *       Filename:  12.cpp
 *
 *    Description: Integer to Roman  
 *
 *        Version:  1.0
 *        Created:  01/25/15 17:38:54
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

const char* info = "IVXLCDM";

string fun(int m, int p)
{
    string r(m, info[p]);
    return r;
}

string getRoman(int m, int p)
{
    string r;
    if(m == 0)
        return r;
    else if(m < 4)
        r = fun(m, p);
    else if (m == 4)
        r = fun(1, p) + fun(1, p+1);
    else if(m < 9)
        r = fun(1, p+1) + fun(m - 5, p);
    else
        r = fun(1, p) + fun(1, p+2);
    return r;
}

string intToRoman(int num)
{
    int p = 0;
    string r;
    while(num)
    {
        int m = num % 10;
        num /= 10;
        r = getRoman(m, p) + r;
        p += 2;
    }
    return r;
}


int main()
{
    int n;
    while(true)
    {
        cin >> n;
        cout << intToRoman(n) << endl;
    }
    return 0;
}
