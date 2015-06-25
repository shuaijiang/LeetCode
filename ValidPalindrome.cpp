/*
*Valid Palindrome
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
    bool isPalindrome(string s) {
    	s = filter(s);
		if(s.size() <=1)
			return true;
        int len = s.length();
        for(int count=0;count<len/2;count++){
        	if(s[count] != s[len-count-1])
        		return false;
        }
        return true;
    }
    
    string filter(string s){
    	if(s == "")
    		return s;
		int len = s.length();
		string str;
		for(int count=0;count<len;++count){
			char  ch = s[count];
			if(ch>='A'&&ch<='Z')
				str.push_back(ch+32);
			else if((ch>='a'&&ch<='z') || (ch>='0'&&ch<='9'))
				str.push_back(ch);
		}
		return str;
    }
};
//The codes under below is used for test
int main(){
	string str("aa");
	Solution s;
	string filter_str = s.filter(str);
	cout<<"Filter="<<filter_str<<endl;
	bool isP = s.isPalindrome(str);
	cout<<"isPalindrome="<<isP<<endl;
	system("pause");
	return 0;
}

