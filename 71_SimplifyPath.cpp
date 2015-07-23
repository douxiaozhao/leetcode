#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string simplifyPath(string path)
    {
        string result;
        vector<string> record;
        int len = path.size();
        temp = new char[len];
        int pos = 0;
        while(pos < len)
        {
            string ans = getFolder(pos, path);
            if(ans.empty())
                break;
            if(ans == ".")
                continue;
            else if(ans == "..")
            {
                if(!record.empty())
                    record.pop_back();
            }
            else
                record.push_back(ans);
        }
        for(vector<string>::iterator it = record.begin(); it != record.end(); ++it)
        {
            result.append("/");
            result.append(*it);
        }
        if(result.empty())
            result.append("/");
        delete[] temp;
        return result;
    }
private:
    string getFolder(int &pos, const string& path)
    {
        int i;
        string ans;
        while(path[pos] == '/')
            ++pos;
        for(i = 0; path[pos+i] != '/' && path[pos+i] != '\0'; ++i)
            temp[i] = path[pos+i];
        pos += i;
        temp[i] = 0;
        return string(temp);
    }

    char* temp;
};


int main()
{
    Solution s;
    string path;
    while(true)
    {
        cin >> path;
        cout << s.simplifyPath(path) << endl;
    }
    return 0;
}
