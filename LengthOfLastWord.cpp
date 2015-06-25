/*
*Length of Last Word
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<string.h>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
    	if(s==" " || s=="")
    		return 0;
    	s = filter(s);
    	int spaceIndex=-1;
    	int len = s.length();
    	for(int count=0;count<len-1;++count){
    		if(s[count] == ' '){
    			spaceIndex = count;
    		}
    	}
    	if(spaceIndex == -1)
    		return len;
    	int wordLen = len - 1 - spaceIndex;
    	return wordLen;
    }
    //Remove the space at the begining or end of the string
    string filter(string s){
    	string str;
    	int begin = 0, end=s.length()-1;
    	while(s[begin] == ' '){
    		begin ++;
    	}
    	while(s[end] == ' '){
    		end --;
    	} 
    	for(int count=begin;count<=end;count++){    		
			str.push_back(s[count]);
    	}
    	return str;
    }
    
};
