/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

Tags: Array
*/

/*
�㷨1��
��ҪO(n)���㷨������ֻ����ʱ�任�ռ䣬�Ȱ�����������Ԫ��ӳ�䵽��ϣ��
Ȼ������Ŀ����������Ϊ��������100�������²���99û�ҵ���Ȼ�����ϲ���101Ҳû�ҵ�����ô����������1���ӹ�ϣ����ɾ��100��
Ȼ����4�����²����ҵ�3,2,1������û���ҵ�5����ô����������4���ӹ�ϣ����ɾ��4,3,2,1��
�����Թ�ϣ�����Ѵ��ڵ�ĳ��Ԫ�����Ϻ����²��ң�ֱ����ϣ��Ϊ�ա��㷨�൱�ڱ�����һ�����飬Ȼ���ٱ�����һ���ϣ�����Ӷ�ΪO(n)��
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
		if(nums.size() == 0) return 0;
		int res = 1;
		unordered_set<int> hashtable;
		for(int i = 0; i < nums.size(); i++)
			hashtable.insert(nums[i]);
		while(!hashtable.empty()){
			int cur = *(hashtable.begin());
			int curLen = 1;
			hashtable.erase(cur);
			
			//��������
			int temp = cur + 1;
			while(!hashtable.empty() && hashtable.find(temp) != hashtable.end()){
				curLen++;
				hashtable.erase(temp);
				temp++;
			}
			
			//�ݼ�����
			temp = cur - 1;
			while(!hashtable.empty() && hashtable.find(temp) != hashtable.end()){
				curLen++;
				hashtable.erase(temp);
				temp--;
			}
			if(curLen > res) res = curLen;
		}
		return res;
    }
};

/*
�㷨2��
�����뵽����������������һ��Ϳ����ҳ���������еĳ��ȣ�ֻ��Ҫ��΢ע�����ж��������еĹ������п�������Ԫ����ͬ������1 2 2 3�������Ӷ�n*log(n)
��Ȼ��ĿҪ��O(n)���Ӷȣ���������ⷨҲ����ͨ��OJ
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
		if(nums.size() == 0) return 0;
		int res = 1;
		sort(nums.begin(), nums.end());
		int curLen = 1;
		for(int i = 1; i < nums.size(); i++){
			if(nums[i] - nums[i-1] == 1){
				curLen++;
			} else if(nums[i] - nums[i-1] == 0){
				;
			} else {
				curLen = 1;
			}
			if(curLen > res) res = curLen;
		}
		return res;
    }
};