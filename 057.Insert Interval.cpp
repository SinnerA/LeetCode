/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

Tags: Array Sort
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
/*
方法一：
原数组上操作
先按照start值找到待插入区间，假设查找到的位置为it，
从it或it-1的位置开始合并区间，直到不能合并为止（合并后的end < 当前区间的start），
删除原数组中参与合并的区间，再插入合并后的新区间
*/
class Solution {
private:
	static int comp(Interval a, Interval b){
		return a.start < b.start;
	}
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval>::iterator it = lower_bound(intervals.begin(), intervals.end(), newInterval, comp);
		if(it != intervals.begin() && newInterval.start <= (it-1)->end){ //ite的上一个区间也可能参与合并
			it--;
			newInterval.start = it->start;
		}
		vector<Interval>::iterator eraseBegin = it;
		for(;it != intervals.end() && newInterval.end >= it->start; it++){
			if(newInterval.end < it->end) newInterval.end = it->end; //合并后的新区间存放于newInterval
		}
		it = intervals.erase(eraseBegin, it); //[eraseBegin, it)是合并时应该删掉的区间
		intervals.insert(it, newInterval);    //插入合并后的区间
		return intervals;
    }
};

/*方法二：新建数组存放结果*/
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> res;
        int i;
		//插入前部分不需要合并的区间
		for(i = 0; i < intervals.size() && newInterval.start > intervals[i].end; i++)
			res.push_back(intervals[i]);
		
		if(i < intervals.size())
			newInterval.start = min(intervals[i].start, newInterval.start);
		for(; i < intervals.size() && newInterval.end >= intervals[i].start; i++)
			if(newInterval.end < intervals[i].end) newInterval.end = intervals[i].end;
		//插入合并后的区间
		res.push_back(newInterval);
		
		//插入剩余区间
		res.insert(res.end(), intervals.begin() + i, intervals.end());
		return res;
    }
};