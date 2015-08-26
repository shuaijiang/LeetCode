/*
*Simplify Path
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<stack>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string result;
        int size = path.size();
        stack<string> myStack;
		string onePart;
		int i=0,j=0;
		for(;i<size;i++){
			int len = i-j-1;
			if(path[i] == '/'){
				if(len > 0){
					onePart = path.substr(j+1,len);
					if(onePart == ".")
						;
					else if(onePart == ".."){
						if(!myStack.empty())
							myStack.pop();
					}
					else
						myStack.push(onePart);
				}				
				j = i;
			}
			else if(i == size - 1 && len >= 0){
				onePart = path.substr(j+1,len+1);
				if(onePart == ".")
					;
				else if(onePart == ".."){
					if(!myStack.empty())
						myStack.pop();
				}
				else
					myStack.push(onePart);
			}
		}

		while(!myStack.empty()){
			if(result.size() == 0)
				result = myStack.top();
			else
				result = myStack.top() + "/" + result;
			myStack.pop();
		}
		result = "/" + result;
		return result;
    }
};

int main(){
	Solution s;
	string path = "/.././GVzvE/./xBjU///../..///././//////T/../../.././zu/q/e";
	string result = s.simplifyPath(path);
	cout<<result<<endl;
	system("pause");
	return 0;
}
