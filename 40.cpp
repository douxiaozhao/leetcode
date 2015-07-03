#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > ans;
        vector<int> intermediate;
        dfs(0, target, candidates, intermediate, ans);
        return ans;
    }

private:
    void dfs(int start, int target, vector<int>& candidates,  vector<int>& intermediate, vector<vector<int> >& ans)
    {
        if(target == 0)
        {
            ans.push_back(intermediate);
            return;
        }

        for(int i = start; i < candidates.size(); ++i)
        {
            if(candidates[i] > target)
                break;
            intermediate.push_back(candidates[i]);
            dfs(i+1, target-candidates[i], candidates, intermediate, ans);
            intermediate.pop_back();
            while(i+1 < candidates.size() && candidates[i+1] == candidates[i])
                ++i;
        }
    }
};

int main()
{
    vector<int> candidates;
    int target = 8;
    candidates.push_back(10);
    candidates.push_back(1);
    candidates.push_back(2);
    candidates.push_back(7);
    candidates.push_back(6);
    candidates.push_back(1);
    candidates.push_back(5);

    Solution s;
    vector< vector<int> > ans = s.combinationSum2(candidates, target);

    for(vector< vector<int> >::iterator it = ans.begin(); it != ans.end(); ++it)
    {
        for(vector<int>::iterator e = it->begin(); e != it->end(); ++e)
            cout << *e << " ";
        cout << endl;
    }

    return 0;
}
