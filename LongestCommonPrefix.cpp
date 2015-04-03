/*
*Longest Common Prefix 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<stringstream>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int vec_len = strs.size();
		string strPrefix ;
		if(vec_len > 0)
		{
			vector<string>::iterator iter;
			iter=strs.begin();
			strPrefix = *iter;
			for(iter=strs.begin();iter<strs.end();++iter)
	        {
	        	strPrefix = commonPrefix(strPrefix,*iter);
	        }
		} 
		else
		{
			strPrefix = "";
		}

        return strPrefix;
    }
    string commonPrefix(string str1, string str2)
	{
		int len = str1.size()>str2.size() ? str2.size(): str1.size();
		string strPrefix;
		for(int count=0;count<len;++count)
		{
			if(str1[count] == str2[count])
			{
				stringstream ss;
				string str_ch;
				ss.clear();
				ss<<str1[count];
				ss>>str_ch;
				strPrefix.append(str_ch);	
			}
			else
				break;
		}
		return strPrefix;
	} 
};
