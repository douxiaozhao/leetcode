#include <iostream>
#include <vector>
using namespace std;

// Definition for an Interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
    {
        vector<Interval> ans;
        int start, end, pos = 0;
        int len = intervals.size();
        for(int i = 0; i < len; ++i, ++pos)
            if(intervals[i].start >= newInterval.start)
                break;
        if(pos == 0)
        {
            start = newInterval.start;
            end = newInterval.end;
        }
        else
        {
            start = intervals[0].start;
            end = intervals[0].end;
        }

        for(int i = 0; i < len; ++i)
        {
            if(pos == i)
            {
                if(newInterval.start <= end)
                {
                    end = max(end, newInterval.end);
                }
                else
                {
                    ans.push_back(Interval(start, end));
                    start = newInterval.start;
                    end = newInterval.end;
                }
            }
            if(intervals[i].start <= end)
            {
                end = max(end, intervals[i].end);
            }
            else
            {
                ans.push_back(Interval(start, end));
                start = intervals[i].start;
                end = intervals[i].end;
            }
        }

        if(pos == len)
        {
            if(newInterval.start <= end)
            {
                end = max(end, newInterval.end);
            }
            else
            {
                ans.push_back(Interval(start, end));
                start = newInterval.start;
                end = newInterval.end;
            }
        }
        ans.push_back(Interval(start, end));
        return ans;
    }

};
