
int climbStairs(int n)
{
    int a, b, c;
    a = b = c = 1;
    for(int i = 2; i <= n; ++i)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}
