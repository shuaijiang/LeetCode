/*
*Isomorphic Strings 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/

#include<iostream>
#include<vector>
#include<map>
#include<string.h>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
    	if(s == t)
    		return true;
        map<char,int> mapS, mapT;
        vector<int>   vectorS,vectorT;
        int countS=0,countT=0;
        for(int count=0;count<s.length();++count){
        	if(mapS.find(s[count]) == mapS.end()){
        		mapS[s[count]] = countS;
        		vectorS.push_back(countS);
        		countS ++;
        	}
        	else{
        		vectorS.push_back(mapS[s[count]]);
        	}
        }
        for(int count=0;count<t.length();++count){
        	if(mapT.find(t[count]) == mapT.end()){
        		mapT[t[count]] = countT;
        		vectorT.push_back(countT);
        		countT ++;
        	}
        	else{
        		vectorT.push_back(mapT[t[count]]);
        	}
        }
        
        for(int count=0;count<vectorS.size();++count){
        	//cout<<"S="<<vectorS[count]<<" "<<"T="<<vectorT[count]<<endl;
        	if(vectorS[count] != vectorT[count])
        		return false;
        }
        return true;
    }
};
//The code under below is used for test
int main(){
	Solution solution;
	string s("ab"), t("ac");
	bool isIs = solution.isIsomorphic(s,t);
	cout<<"isIs="<<isIs<<endl;
	system("pause");
	return 0;
}
