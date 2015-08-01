/*
*Valid Anagram 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<string>
#include<map> 
#include<stdlib.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int size1 = s.size();
        int size2 = t.size();
        map<char, int> myMap;
        if(size1 != size2)
        	return false;
        if(size1 == 1 && size2 == 1) {
        	if(s[0] == t[0])
        		return true;
        	else
        		return false;
        }
        for(int i=0;i<size1;i++){
			if(myMap.find(s[i]) == myMap.end())
				myMap[s[i]] = 1;
			else
				myMap[s[i]] += 1;
        }

        for(int i=0;i<size1;i++){
        	if(myMap.find(t[i]) == myMap.end())      		
        		return false;
        	else if(myMap[t[i]] == 0)
        		return false;
        	else
        		myMap[t[i]] --;
        }
        return true;
    }
};
