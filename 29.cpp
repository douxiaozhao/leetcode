#include <iostream>
#include <vector>
using namespace std;

int divide(int dividend, int divisor)
{
    if(divisor == 0)
        return INT_MAX;

    int flag = 1;
    if((dividend < 0 && divisor >0) || (dividend > 0 && divisor < 0))
        flag = -1;

    long long divid = abs((long long)dividend);
    long long divis = abs((long long)divisor);

    long long result = 0;
    while( divid >= divis )
    {
        long long cnt = 1;
        long long temp = divis;
        while((temp <<= 1) <= divid)
        {
            cnt <<= 1;
        }
        result += cnt;
        divid -= (temp >> 1);
    }

    result *= flag;
    if(result > INT_MAX)
        return INT_MAX;
    return result;
}

int main()
{
    int a, b;
    while(true)
    {
        cin >> a;
        cin >> b;
        cout << divide(a, b) << endl;
        cout << INT_MAX << endl;
    }
    return 0;
}
