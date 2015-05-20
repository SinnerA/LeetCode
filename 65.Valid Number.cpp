/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.

Tags: Math String
*/

/*
����һ�����ñ�־λ
*/
class Solution {
public:
    bool isNumber(string s) {
		if(s.empty()) return false;
		//��ʾ�������������
		bool canSign = true;           //�´��ܷ����+-
		bool canE = false;             //�´��ܷ����e
		bool haveE = false;            //�Ƿ��Ѿ�����e
		bool canDot = true;            //�´��ܷ����.
		bool havaSpaceAfterNum = false;//�Ƿ�����ֵ�����Ѿ����ֿո�
		bool canNum = false;           //�´��ܷ������ֵ
		bool haveNum = false;          //�Ƿ��Ѿ�������ֵ
		int i = 0;
		char ch = ' ';
		while((ch = s[i++]) != '\0'){
			if(ch == ' '){
				if(canNum)
					havaSpaceAfterNum = true; //canNum == true��˵��ǰ���Ѿ�������ֵ������ݣ���+-�Լ�.֮���
				continue;
			} else if(havaSpaceAfterNum){
				return false;
			}
			if(ch == '+' || ch == '-'){
				if(!canSign) return false;
				canSign = false;
				canNum = true;
				continue;
			}
			if(ch == 'e'){
				if(!canE) return false;
				canSign = true;  //e֮����Խ����ų���+-
				canE = false;
				haveE = true;
				canDot = false;
				canNum = true;
				haveNum = false; //����e�����¼�¼�Ƿ������ֵ
				continue;
			}
			if(ch == '.'){
				if(!canDot) return false;
				canSign = false;
				//canE = false; //.֮����Խ����ų���e
				canDot = false;
				canNum = true;
				continue;
			}
			if(ch >= '0' && ch <= '9'){
				//if(!canNum) return false; //canNum���Դ�Լ��
				canSign = false;
				if(!haveE) canE = true;
				canNum = true;
				haveNum = true;
				continue;
			} else {
				return false;
			}
		}
		return haveNum;
    }
};

/*
�������������жϣ��߼��Բ� http://www.cnblogs.com/TenosDoIt/p/3475305.html
*/


/*
������������״̬�� http://www.cnblogs.com/chasuner/p/validNumber.html
*/