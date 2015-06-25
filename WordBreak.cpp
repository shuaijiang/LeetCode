/*
*Word Break
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/

#include<iostream>
#include<vector>
#include <unordered_set>
#include<string.h>
#include<stdlib.h>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if(wordDict.find(s)!=wordDict.end())
        	return true;
        vector<int> wordIndex;
		int sublen = 0, subBegin = 0, subEnd = 0;
        string substr;
        wordIndex.push_back(-1);
		for(int count=0;count<s.length();++count){
			for(int i=0;i<wordIndex.size();i++){
				subBegin = wordIndex[i]+1;
				sublen = count - subBegin + 1;
	        	substr = s.substr(subBegin,sublen);
				if(wordDict.find(substr)!=wordDict.end()){
					wordIndex.push_back(count);
					break;
				}
			}
        }
        int len = wordIndex.size();
        if(wordIndex[len-1] == s.length()-1)
			return true;
		else
        	return false;
    }
};
