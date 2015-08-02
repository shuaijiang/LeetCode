/*
*Anagrams
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
    vector<string> anagrams(vector<string>& strs) {
        int size = strs.size();
        map<string, int> myMap;
		vector<string> result;
		if(size <= 0)
			return result;
			
        for(int i=0;i<size;i++){
			string str = strs[i];
			sort(str.begin(),str.end());
			if(myMap.find(str) == myMap.end()){
				myMap[str] = i;
			}
			else{
				if(myMap[str] >= 0){
					result.push_back(strs[myMap[str]]);
					myMap[str] = -1;
				}
				result.push_back(strs[i]);
			}
        }
        return result;
    }
};
