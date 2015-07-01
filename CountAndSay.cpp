/*
*Count and Say 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
    	if(n==0)
    		return "";
        if(n==1)
        	return "1";
        string str("1");
        for(int i=1;i<n;i++){
        	str = countNext(str);
        }
        return str;
    }
    string countNext(string str){
    	int count = 1;
    	char lastCh=str[0],countCh;
    	string newStr;
    	for(int i=1;i<str.length();++i){
    		if(str[i]==lastCh){
    			count ++;
    		}
    		else{
    			countCh = '0'+count;
    			newStr.push_back(countCh);
    			newStr.push_back(lastCh);
    			lastCh = str[i];
    			count = 1;
    		}
    	}
    	countCh = '0'+count;
		newStr.push_back(countCh);
		newStr.push_back(lastCh);
    	return newStr;
    }
};

int main()
