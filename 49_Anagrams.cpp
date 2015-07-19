#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string>& strs)
    {
        vector<string> ans;
        map<string,int> record;
        map<string,int>::iterator iter;
        int len = strs.size();

        for(int i = 0; i < len; ++i)
        {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());

            iter = record.find(tmp);
            if(iter != record.end())
            {
                if(iter->second != -1)
                {
                    ans.push_back(strs[iter->second]);
                    iter->second = -1;
                }
                ans.push_back(strs[i]);
            }
            else
                record.insert(make_pair(tmp, i));
        }

        return ans;
    }
};
