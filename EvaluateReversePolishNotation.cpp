/*
*Evaluate Reverse Polish Notation
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector> 
#include<stack>
#include<sstream>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int size = tokens.size();
        stack<string> myStack;
        stringstream ss;
        for(int i=0;i<size;i++){
        	if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
        		int num2;
				ss<<myStack.top();
        		ss>>num2;
        		ss.clear();
        		myStack.pop();
        		int num1;
				ss<<myStack.top();
        		ss>>num1;
        		ss.clear();
        		myStack.pop();
        		int num = 0;
        		if(tokens[i]=="+")
        			num = num1 + num2;
        		else if(tokens[i]=="-")
        			num = num1 - num2;
        		else if(tokens[i]=="*")
        			num = num1 * num2;
        		else
        			num = num1 / num2;
        		string strNum;
        		ss<<num;
        		ss>>strNum;
        		ss.clear();
        		myStack.push(strNum);
        	}
        	else
        		myStack.push(tokens[i]);
        }
		int result;
        ss<<myStack.top();
        ss>>result;
        ss.clear();
        return result;
    }
};

