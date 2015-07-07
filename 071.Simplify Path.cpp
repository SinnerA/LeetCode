/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".

Tags: Stack String
*/

/*
需要注意的是/...可以表示名字为...的路径，路径的最后可能没有/。
可以利用栈，碰到正常路径压入栈中，碰到/.不作任何操作，碰到/..删除栈顶元素。下面代码中用数组来模拟栈
*/
class Solution {
public:
    string simplifyPath(string path) {
        string res;
		if(path.empty()) return res;
		vector<string> vec;
		int n = path.size(), i = 0;
		
		while(i < n){
			string curStr;
			int j = path.find('/', i + 1);
			if(j != string::npos){
				curStr = path.substr(i, j - i);
			} else {
				curStr = path.substr(i, n);    //截取后面所有字符
				j = n;
			}
			
			if(curStr == "/");
			else if(curStr == "/.");
			else if(curStr == "/.."){
				if(!vec.empty()) vec.pop_back();
			} else {
				vec.push_back(curStr);
			}
			
			i = j;
		}
		
		if(vec.empty()){
			res = "/";
		} else {
			for(int i = 0; i < vec.size(); i++){
				res += vec[i];
			}
		}
		return res;
    }
};