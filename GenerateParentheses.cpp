/*
*Generate Parentheses 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
  		vector<string> result;
  		if(n<=0)
  			return result;
		string str="";
		generate(result,str,n,n);
		return result;
    }
    void generate(vector<string>& result,string str, int left, int right){
    	if(left == 0 && right == 0){
    		result.push_back(str);
    	}
    	string str1 = str;
    	if(left > 0){
    		str.push_back('(');
    		generate(result,str,left-1,right);
    	}

    	if(left < right){
    		str1.push_back(')');
    		generate(result,str1,left,right-1);
    	}
    	return;
    }
};


