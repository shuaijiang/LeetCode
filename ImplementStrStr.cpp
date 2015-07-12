/*
*Implement strStr()  
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
		int i, j;
        for (i = j = 0; i < haystack.size() && j < needle.size();) {
        	if (haystack[i] == needle[j]){
            	++i; ++j;
            }
        	else{
        		i -= j - 1; j = 0;
        	}
        }
        return j != needle.size() ? -1 : i - j;
    }
};
