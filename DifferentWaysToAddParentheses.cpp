/*
*Different Ways to Add Parentheses 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        int num = 0;
    	int i = 0, len = input.size(); 
    	for(i=0;i < len && input[i] >='0' && input[i] <= '9';i++){
    		num = num * 10 + (input[i] - '0');
    	}
    	vector<int> result;
    	
    	if(i >= len){
    		result.push_back(num);	
    		return result;
    	}   		
    	
    	for(int j=0;j<len;j++){
    		if(input[j] == '+' || input[j] == '-' || input[j] == '*'){
    			char op = input[j];
	    		string left  = input.substr(0,j);
	    		string right = input.substr(j+1, len - j -1);
	    		vector<int> vecLeft  = diffWaysToCompute(left);
	    		vector<int> vecRight = diffWaysToCompute(right);
	    		
	    		for(int k=0;k<vecLeft.size();k++){
	    			for(int m=0;m<vecRight.size();m++){
	    				int val = 0;
						if(op == '+')
	    					val = vecLeft[k] + vecRight[m];
	    				else if(op == '-')
	    					val = vecLeft[k] - vecRight[m];
	    				else if(op == '*')
	    					val = vecLeft[k] * vecRight[m];
	    				result.push_back(val);
	    			}
	    		}
    		}    		
    	}
    	return result;
    }
};

int main(){
	Solution s;
	string input("2*3-4*5");
	vector<int> res = s.diffWaysToCompute(input);
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<endl;
	}
	system("pause");
	return 0;
}
