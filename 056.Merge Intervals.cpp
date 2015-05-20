/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

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
 
/*先对区间左边界排序，然后顺序扫描，合并重叠的区间*/

/*方法一：原数组上操作，需要删除多余的区间，会移动数组元素*/
class Solution {
private:
	static bool comp(Interval a, Interval b){
		return a.start < b.start;
	}
public:
    vector<Interval> merge(vector<Interval>& intervals) {
		if(intervals.empty()) return intervals;
        sort(intervals.begin(), intervals.end(), comp);
		vector<Interval>::iterator ite1 = intervals.begin(), ite2 = ite1 + 1;
		while(ite1 != intervals.end() && ite2 != intervals.end()){
			if(ite1->end >= ite2->start){
				if(ite1->end < ite2->end)
					ite1->end = ite2->end;
				ite2++;
			} else {
				//原数组中删除多余区间
				ite1 = intervals.erase(ite1+1, ite2);
				ite2 = ite1 + 1;
			}
		}
		if(ite2 == intervals.end())
			intervals.erase(ite1+1, ite2);
		return intervals;
    }
};

/*方法二：开辟新数组，用来存储新的区间*/
class Solution {
private:
	static bool comp(Interval a, Interval b){
		return a.start < b.start;
	}
public:
    vector<Interval> merge(vector<Interval>& intervals) {
		if(intervals.empty()) return intervals;
		sort(intervals.begin(), intervals.end(), comp);
		vector<Interval> res;
		res.push_back(intervals[0]);
		for(int i = 1; i < intervals.size(); i++){
			Interval& p = res.back();
			if(p.end < intervals[i].start)
				res.push_back(intervals[i]);
			else if(p.end < intervals[i].end)
				p.end = intervals[i].end;
		}
		return res;
    }
};
