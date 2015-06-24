/*
*Valid Parentheses 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<math.h>
#include<stack>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
    	if(s.size() <= 0)
    		return true;
    	if(s.size() == 1)
    		return false;
        stack<char> myStack;
        for(int count=0;count<s.size();++count){
        	if(myStack.empty())
        		myStack.push(s.at(count));
        	else{
        		if(abs(s.at(count) - myStack.top()) <= 2 && abs(s.at(count) - myStack.top()) > 0)
        			myStack.pop();
        		else
        			myStack.push(s.at(count));
        	}
        }
        if(myStack.empty())
			return true;
        else
        	return false;
    }
};

int main(){
	Solution s;
	string str("[(])");
	bool isV = s.isValid(str);
	cout<<"isValid="<<isV<<endl;
	
	system("pause");
	return 0;
}
