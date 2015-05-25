/*
Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.
Tags: Array Backtracking Breadth-first Search String
*/

/*
分析：本题主要的框架和"Word Ladder"是一样，但是还要解决两个额外的问题：一、 怎样保证求得所有的最短路径；二、 怎样构造这些路径

第一问题：
1：不能像"Word Ladder"题中那样，找到一个单词相邻的单词后就立马把它从字典里删除，因为当前层还有其他单词可能和该单词是相邻的，这也是一条
最短路径，比如hot->hog->dog->dig和hot->dot->dog->dig，找到hog的相邻dog后不能立马删除，因为和hog同一层的单词dot的相邻也是
dog，两者均是一条最短路径。但是为了避免进入死循环，再hog、dot这一层的单词遍历完成后dog还是得从字典中删除。即等到当前层所有
单词遍历完后，和他们相邻且在字典中的单词要从字典中删除。
2：如果像上面那样没有立马删除相邻单词，就有可能把同一个单词加入bfs队列中，这样就会有很多的重复计算（比如上面例子提到的dog就会被2次加
入队列）。因此我们用一个哈希表来保证加入队列中的单词不会重复，哈希表在每一层遍历完清空（代码中hashtable）。
3：当某一层的某个单词转换可以得到end单词时，表示已经找到一条最短路径，那么该单词的其他转换就可以跳过。并且遍历完这一层以后就可以跳出
循环，因为再往下遍历，肯定会超过最短路径长度

第二个问题：
1：为了输出最短路径，我们就要在比bfs的过程中保存好前驱节点，比如单词hog通过一次变换可以得到hot，那么hot的前驱节点就包含hog，每个单
词的前驱节点有可能不止一个，那么每个单词就需要一个数组来保存前驱节点。为了快速查找因此我们使用哈希表来保存所有单词的前驱路径，哈希
表的key是单词，value是单词数组。（代码中的unordered_map<string,vector<string> >prePath）
2：有了上面的前驱路径，可以从目标单词开始递归的构造所有最短路径（代码中的函数 constructPath）
*/

class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        unordered_map<string, vector<string> > prePath; //保存前驱节点
		unordered_set<string> hashtable;                //保存每一层加入队列的单词，保证加入队列的单词不会重复
		int strLen = start.size();                      //单词长度
		bool isFound = false;                           
		queue<string> myQueue;
		myQueue.push(start);
		myQueue.push("");                               //""为每一层的分割点
		while(!myQueue.empty()){
			string str = myQueue.front();
			myQueue.pop();
			string savedPreStr = str;
			if(str != ""){
				for(int i = 0; i < strLen; i++){
					char temp = str[i];
					for(char ch = 'a'; ch <= 'z'; ch++){
						if(temp == ch) continue;
						str[i] = ch;
						if(str == end){
							//找到最短路径
							isFound = true;
							prePath[end].push_back(savedPreStr);
							break;
						}
						if(dict.find(str) != dict.end()){
							prePath[str].push_back(savedPreStr);
							//避免重复入队
							if(hashtable.find(str) == hashtable.end()){
								myQueue.push(str);
								hashtable.insert(str);
							}
						}
					}
					if(isFound && str == end) break;
					str = savedPreStr;
				}
			} else if(!myQueue.empty()){
				if(isFound) break;
				//遍历完一层，但没有遍历完所有层
				for(unordered_set<string>::iterator it = hashtable.begin(); it != hashtable.end(); it++)
					dict.erase(*it); //删除本层单词，否则路径会进入循环
				hashtable.clear();
				myQueue.push("");
			}
		}
		//构建每条路径
		vector<vector<string> > res;
		if(prePath.find(end) == prePath.end()) return res;
		vector<string> tempRes;
		tempRes.push_back(end);
		constructPath(prePath, tempRes, res, start, end);
		return res;
    }
private:
	//从前驱路径中回溯构造path
	void constructPath(unordered_map<string, vector<string> >& prePath, vector<string>& tempRes, 
	                   vector<vector<string> >& res, string& start, string& end){
		if(start == end){
			reverse(tempRes.begin(), tempRes.end());
			res.push_back(tempRes);
			reverse(tempRes.begin(), tempRes.end());
			return;
		}
		vector<string>& pre = prePath[end];
		for(int i = 0; i < pre.size(); i++){
			tempRes.push_back(pre[i]);
			constructPath(prePath, tempRes, res, start, pre[i]);
			tempRes.pop_back();
		}
	}
};

















