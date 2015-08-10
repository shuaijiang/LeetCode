/*
*Repeated DNA Sequences
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<map>
#include<stdlib.h>
#define Code 0x3ffff 
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int size = s.size();
        vector<string> res;
        if(size <= 10)
        	return res;
        map<int, int> myMap;
        map<char, int> char2int; // = {{'A',0},{'C',1},{'G',2},{'T',3}};
        char2int['A'] = 0;
        char2int['C'] = 1;
        char2int['G'] = 2;
        char2int['T'] = 3;
        int strInt = 0;
        for(int i=0;i<10;i++){
        	strInt = (strInt << 2) + char2int[s[i]];
        }
        myMap[strInt] = 1;
        
		for(int i=10; i<size; i++){
			strInt = ((strInt & Code) << 2) + char2int[s[i]];     	
        	if(myMap.find(strInt) == myMap.end())
        		myMap[strInt] = 1;
        	else{
        		if(myMap[strInt] == 1){
        			string substr = s.substr(i-9,10);
        			res.push_back(substr);
        		}
        		myMap[strInt] ++;
        	}
        }
        return res;
    }
};

int main(){
	Solution s;
	string str("GAGAGAGAGAGA");
	
	vector<string> res = s.findRepeatedDnaSequences(str);
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<endl; 
	}
	system("pause");
	return 0;
}
