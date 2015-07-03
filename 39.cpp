#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Solution{
public:
    vector< vector<int> > combinationSum(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        map<int, vector< vector<int> > > record;
        vector< vector<int> > head, ans;
        head.push_back(vector<int>());
        record.insert(make_pair(0, head));

        for(vector<int>::iterator it = candidates.begin(); it != candidates.end(); ++it)
            addElement(*it, target, record);

        map<int, vector< vector<int> > >::iterator it = record.find(target);
        if(it != record.end())
            ans = it->second;
        return ans;
    }

private:
    void addElement(int can, int target, map<int, vector< vector<int> > >& record)
    {
        vector< vector<int> > head;

        map<int, vector< vector<int> > >::iterator it, next;
        it = record.begin();

        while(it != record.end())
        {
            int num = it->first;
            int sum = num + can;
            if(sum > target)
                break;

            next = record.find(sum);
            if(next == record.end())
            {
                record.insert(make_pair(sum, head));
                it = record.find(num);
                next = record.find(sum);
            }

            for(vector< vector<int> >::iterator v = it->second.begin(); v != it->second.end(); ++v)
            {
                vector<int> temp = *v;
                temp.push_back(can);
                next->second.push_back(temp);
            }

            ++it;
        }
    }
};

int main()
{
    vector<int> candidates;
    int target = 7;
    candidates.push_back(2);
    candidates.push_back(3);
    candidates.push_back(6);
    candidates.push_back(7);

    Solution s;
    vector< vector<int> > ans = s.combinationSum(candidates, target);

    for(vector< vector<int> >::iterator it = ans.begin(); it != ans.end(); ++it)
    {
        for(vector<int>::iterator e = it->begin(); e != it->end(); ++e)
            cout << *e << " ";
        cout << endl;
    }

    return 0;
}
