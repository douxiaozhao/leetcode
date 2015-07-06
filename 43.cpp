#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string multiply2(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        int l1 = num1.length(), l2 = num2.length();
        int* n1 = new int[l1];
        int* n2 = new int[l2];
        int* res = new int[l1+l2];
        memset(res,0,sizeof(int)*(l1+l2));
        for(int i=0; i<l1; ++i)
            n1[i] = num1[i] - '0';
        for(int i=0; i<l2; ++i)
            n2[i] = num2[i] - '0';

        for(int i=0; i<l1; ++i)
            for (int j=0; j<l2; ++j)
                res[i+j+1] += n1[i]*n2[j];

        string ss = "";
        for (int k=l1+l2-1; k>=0; --k){
            if(k>0) res[k-1] += res[k]/10;
            res[k] %= 10;
            ss = char(res[k]+'0')+ss;
        }
        ss = ss[0]=='0'? ss.substr(1):ss;
        //return ss.empty()?"0":ss;
        return ss;
    }

    string multiply(string num1, string num2) {
        string ans = "0";
        int len2 = num2.size();
        for(int i = len2-1; i >= 0; --i)
        {
            if(num2[i] == '0')
                continue;
            string temp = getMul(num1, num2[i]-'0', len2-i-1);
            ans = addTwoString(ans, temp);
        }
        return ans;
    }

private:
    string addTwoString(string num1, string num2)
    {
        int len1 = num1.size(), len2 = num2.size();
        char* ans = new char[max(len1, len2)+1];
        int i = len1-1, j = len2-1, k = 0, carry = 0;
        while(i >=0 && j >= 0)
        {
            int sum = (num1[i--]-'0')+(num2[j--]-'0')+carry;
            ans[k++] = sum%10 + '0';
            carry = sum/10;
        }
        while(i >= 0)
        {
            int sum = (num1[i--]-'0')+carry;
            ans[k++] = sum%10 + '0';
            carry = sum/10;
        }
        while(j >= 0)
        {
            int sum = (num2[j--]-'0')+carry;
            ans[k++] = sum%10 + '0';
            carry = sum/10;
        }
        if(carry>0)
            ans[k++] = carry+'0';
        ans[k] = 0;

        for(int i = 0; i < k/2; ++i)
        {
            int temp = ans[i];
            ans[i] = ans[k-i-1];
            ans[k-i-1] = temp;
        }
        string result(ans);
        delete[] ans;
        return result;
    }

    string getMul(string num, int c, int count)
    {
        int carry = 0, len = num.size(), k = 0;
        char *ans = new char[len+1+count];

        for(int i = len-1; i >= 0; --i)
        {
            int temp = (num[i]-'0')*c+carry;
            ans[k++] = temp%10 + '0';
            carry = temp/10;
        }
        if(carry > 0)
            ans[k++] = '0' + carry%10;
        for(int i = 0; i < k/2; ++i)
        {
            int temp = ans[i];
            ans[i] = ans[k-i-1];
            ans[k-i-1] = temp;
        }
        for(int i =0; i < count; ++i)
            ans[k++] = '0';
        ans[k] = 0;
        string result(ans);
        delete[] ans;
        return result;
    }
};

int main()
{
    string n1, n2;
    Solution s;
    while(true)
    {
        cin >> n1;
        cin >> n2;
        cout << s.multiply(n1, n2) << endl;
    }
    return 0;
}
