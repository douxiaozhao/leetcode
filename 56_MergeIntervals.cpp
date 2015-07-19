#include <iostream>
#include <vector>
using namespace std;

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals)
    {
        vector<Interval> ans;
        if(intervals.empty())
            return ans;
        int start, end;
        sort(intervals.begin(), intervals.end(), cmp);
        start = intervals[0].start;
        end = intervals[0].end;

        for(vector<Interval>::iterator it = intervals.begin()+1; it != intervals.end(); ++it)
        {
            if(it->start > end)
            {
                ans.push_back(Interval(start, end));
                start = it->start;
                end = it->end;
            }
            else
                end = max(end, it->end);
        }
        ans.push_back(Interval(start, end));
        return ans;
    }

private:
    static bool cmp(const Interval& a, const Interval& b)
    {
        if(a.start < b.start)
            return true;
        return false;
    }

};
