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
 
/*�ȶ�������߽�����Ȼ��˳��ɨ�裬�ϲ��ص�������*/

/*����һ��ԭ�����ϲ�������Ҫɾ����������䣬���ƶ�����Ԫ��*/
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
				//ԭ������ɾ����������
				ite1 = intervals.erase(ite1+1, ite2);
				ite2 = ite1 + 1;
			}
		}
		if(ite2 == intervals.end())
			intervals.erase(ite1+1, ite2);
		return intervals;
    }
};

/*�����������������飬�����洢�µ�����*/
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
