/*
*Restore IP Addresses
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

class Solution {
public:
	vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        string str;
        dfs(s, str, 0);
        return res;
    }
    bool dfs(string s, string str, int level){
    	stringstream ss;
    	int num;
		
		if(level == 3){
			ss<<s;
	    	ss>>num;
	    	ss.clear();
	    	
	    	if(s[0] == '0' && s.size()>1) //if one part has more than 1 integer, the begining can't be 0 
	    		return false;
			if(num <= 255){
				str.push_back('.');
				str+=s;
				res.push_back(str);
				return true;
			}
			return false;
		}
		string substr;
		string remain;
		for(int i=0;i<3 && i<s.size();++i){
			substr = s.substr(0,i+1);
			if(substr[0] == '0' && substr.size() > 1)
				continue;
			ss<<substr;
			ss>>num;
			ss.clear();
			if(num <= 255){
				if(str.size()>0) // if first part should not add '.'
					str.push_back('.');
				str += substr;
				remain = s.substr(i+1, s.size()-i-1);
				
				if(remain.size() >= 3-level)
					dfs(remain, str, level+1);
				
				if(str == substr)
					str = "";
				else
					str = str.substr(0, str.size() - substr.size() - 1);
			}
			else{
				return false;
			}
		}
    }
};

int main(){
	Solution s;
	//string str("25525511135");
	string str("010010");
	vector<string> res = s.restoreIpAddresses(str);
	for(int i=0;i<res.size();++i){
		cout<<res[i]<<endl;
	}
	return 0;
}
