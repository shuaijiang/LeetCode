/*
*Substring with Concatenation of All Words 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int wordsNum = words.size();
		if(wordsNum <= 0)
			return result;
		int wordLen = words[0].size();
		int strLen  = s.size();
		if(strLen <= 0 || strLen < wordLen)
			return result;
		
		map<string, int> wordMap;
		for(int i=0;i<wordsNum;i++)
			++ wordMap[words[i]];
		
		int subLen = wordsNum * wordLen; 
		for(int i=0;i<=strLen - subLen;i++){
			map<string, int> myMap(wordMap);
			for(int j=i;j<i+subLen;j+=wordLen){
				string substr = s.substr(j,wordLen);
				if(myMap.find(substr) != myMap.end()){
					myMap[substr] --;
					if(myMap[substr] == 0)
						myMap.erase(substr);
				}					
				else
					break;
			}
			if(myMap.size() == 0)
				result.push_back(i);
		}
		return result;
    }
};
