#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        string result;
        vector<int> fact;
        vector<int> elements;

        for(int i = 0; i < n; ++i)
        {
            if(!i)
                fact.push_back(1);
            else
                fact.push_back(i*fact[i-1]);
            elements.push_back(i+1);
        }

        int pos = 0;
        for(int i = n-1; i >= 0; --i)
        {
            pos = (k-1) / fact[i];
            k -= pos * fact[i];
            result.push_back('0' + elements[pos]);
            elements.erase(elements.begin()+pos);
        }
        return result;
    }

private:
};


int main()
{
    int n, k;
    Solution s;
    while(true)
    {
        cin >> n;
        cin >> k;
        cout << s.getPermutation(n, k) << endl;
    }
    return 0;
}
