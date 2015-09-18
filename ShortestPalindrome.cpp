/*
*Shortest Palindrome
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
	//Manacher algorithm
	int longestPalindrom(string s) {
        int len = s.size();
		string s1;
        s1.resize(2 * s.length() + 2);
        int idx = 0;
        s1[idx++] = '$';
        s1[idx++] = '#';
        for (int i=0;i<s.size(); i++) {
            s1[idx++] = s[i];
            s1[idx++] = '#';
        }
        vector<int> p(s1.length(), 0);
        int res = 0;
        for (int id = 0, i = 1; i < s1.length(); ++i) {
            if (i < id + p[id]) 	// mx = id + p[id]
				p[i] = min(p[2 * id - i], id + p[id] - i);
            else 
				p[i] = 1;
            //compute the p
            while (s1[i + p[i]] == s1[i - p[i]]) 
				++p[i];
			
            if (id + p[id] < i + p[i]) 
				id = i;
            //the palindrome start from the beginning
			if (p[i] == i)
				res = max(res, i);
        }
        return res - 1;
    }
    string shortestPalindrome(string s) {
        int len = s.size();
		if(len <= 1)
			return s;
		int index = longestPalindrom(s) - 1;
		cout<<"index="<<index<<endl;
		string res;
		for(int i=len-1;i>index;i--)
			res.push_back(s[i]);
		res = res + s;
		
		return res;
    }
};

int main(){
	Solution s;
	string str("aacecaaa") ;
	//string str("ba") ;
	string res = s.shortestPalindrome(str);
	cout<<"res="<<res<<endl;
	system("pause");
	return 0;
}
