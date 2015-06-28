/*
*Basic Calculator
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<stack>
#include<string.h>
#include<sstream>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
    	stack<char> myStack;
    	string substr="",totalStr;
        int sign=1;
        int num=0, total = 0;
        for(int i=0;i<s.length();i++){
        	if(s[i]=='(' || s[i]=='+' || s[i]=='-')
        		myStack.push(s[i]);
        	else if(s[i]>='0' && s[i]<='9'){
        		myStack.push(s[i]);
        	}
        	else if(s[i]==')'){
				while(myStack.top() != '('){
					substr.push_back(myStack.top());
					myStack.pop();
				}
				myStack.pop();
				totalStr = compute(substr);
				//cout<<"totalStr="<<totalStr<<endl;
				
				if(totalStr[0]=='-' && !myStack.empty()){
					if(myStack.top()=='+')
						myStack.pop();
					if(myStack.top()=='-'){
						totalStr[0] = '+';
						myStack.pop();
					}
				}
				for(int j=0;j<totalStr.length();j++){
					myStack.push(totalStr[j]) ;
				}
				substr="";
        	}
        }
        while(!myStack.empty()){
        	substr.push_back(myStack.top());
        	myStack.pop();
        }
        totalStr = compute(substr);
        substr="";
		total = atoi(totalStr.c_str()) ;
        return total;
    }
    string compute(string str){
    	string s,totalStr;
    	stringstream ss;
    	for(int i=str.length()-1;i>=0;i--){
    		s.push_back(str[i]);
    	}
    	int sign=1;
        int num=0, total = 0;
        for(int i=0;i<s.length();i++){
        	if(s[i]>='0' && s[i]<='9'){
        		num = num * 10 + (s[i]-'0');
        	}
        	else{
        		total = total + sign * num;
        		num = 0;
        		if(s[i]== '+')
        			sign = 1;	
        		else if(s[i]=='-')
					sign = -1;
        	}
        }
        total += sign * num;
        ss<<total;
        ss>>totalStr;
        return totalStr;
    }
};
//The code under below is used for test
int main(){
	string str("(5-(1+(5)))");
	Solution s;
	int result = s.calculate(str);
	cout<<"result="<<result<<endl;
	system("pause");
	return 0;
}
