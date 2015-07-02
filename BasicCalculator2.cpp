/*
*Basic Calculator2
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<string.h>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
    	if(s.length() <= 0)
    		return 0;
    	s.push_back(' ');
    	vector<int>  myNumber;
		vector<char> myOperator;
		int num=0, sizeO=0, sizeN=0;
		bool isNum = false;
        for(int i=0;i<s.length();i++){
        	cout<<"s["<<i<<"]="<<s[i]<<endl;
        	if(s[i]>='0' && s[i]<='9'){
        		num = num * 10 + (s[i]-'0');
        		isNum = true;
        	}
        	else{
        		if(isNum){
        			isNum = false;
        			sizeO = myOperator.size();
        			sizeN = myNumber.size();
        			if(sizeN == 0){
        				myNumber.push_back(num);
        			}
        			else{
	        			cout<<"sizeO="<<sizeO<<endl<<"sizeN="<<sizeN<<endl;
	        			if(myOperator[sizeO-1] =='*'){
	        				myNumber[sizeN-1]  *=  num;
	        				myOperator.pop_back();
	        			}
	        			else if(myOperator[sizeO-1]=='/'){
	        				myNumber[sizeN-1]  /=  num;
	        				myOperator.pop_back();
	        			}
	        			else{
	        				myNumber.push_back(num);
	        			}
	        		}
	        		num = 0;
        		}
				if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
					cout<<"!!s="<<s[i]<<endl;
					myOperator.push_back(s[i]);
				}
        			
        	}
    	}
		if(myNumber.size()==0)
			return 0;
        if(myNumber.size()==1)
        	return myNumber[0];
        int total = myNumber[0];
        for(int i=1;i<myNumber.size();i++){
        	if(myOperator[i-1]=='+')
        		total += myNumber[i];
        	else if(myOperator[i-1]=='-')
        		total -= myNumber[i];
        }
        return total;
    }
};

int main(){
	Solution s;
	string str("2*3+4") ;
	int num = s.calculate(str);
	cout<<"num="<<num<<endl;
	system("pause");
	return 0;
}
