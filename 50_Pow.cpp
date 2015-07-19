class Solution {
public:
    double myPow(double x, int n)
    {
        if(n == 0)
            return 1;
        else if(n == 1)
            return x;

        int m = (n > 0 ? n : n*-1);

        double ans = (m % 2 == 0 ? (myPow(x*x, m>>1)) : (myPow(x*x, m>>1))*x);

        return (n > 0 ? ans : 1/ans);
    }
};
