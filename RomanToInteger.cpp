/*
*Roman to Integer 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
    	int len = s.size();
    	if(len<=0)
    		return 0;
        char roman[] = {'I','V','X','L','C','D','M'};
        int  myInt[] = {1,5,10,50,100,500,1000};
        map<char, int> romanMap;
        for(int i=0;i<7;i++)
        	romanMap[roman[i]] = myInt[i];
		int result = 0;
		result += romanMap[s[0]];
		char lastCh = s[0];
		for(int i=1;i<len;i++){
			if(romanMap[lastCh] < romanMap[s[i]]){
				result = result - 2*romanMap[lastCh] + romanMap[s[i]];
				lastCh = s[i];
			}
			else{
				result = result + romanMap[s[i]];
				lastCh = s[i];
			}
		}
		return result;
    }
};
