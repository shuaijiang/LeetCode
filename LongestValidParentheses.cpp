/*
*Longest Valid Parentheses 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<stack>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        if( len <= 0)
        	return 0;
        stack<int> myStack; // save the index of '('
        int maxLen = 0, last = -1;
        for(int i=0; i<len; i++){
        	if(s[i] == '(')
				myStack.push(i);
			else{
				if(!myStack.empty()){
					myStack.pop();
					if(myStack.empty())
						maxLen = max(maxLen, i-last);
					else
						maxLen = max(maxLen, i-myStack.top());
				}
				else{
					last = i;
				}
			}
        }
        return maxLen;
    }
};
