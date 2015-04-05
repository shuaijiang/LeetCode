/*
*Excel Sheet Column Number 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
    	int num = 0;
    	int bit_num = 0;
        int len = s.size();
		for(int count=len-1;count>=0;count--,bit_num ++)
		{
			int diff = s[count]-'A' + 1;
			num += diff * pow(26,bit_num);
		} 
		return num;
    }
}; 

int main()
{
	
	string str("AB");
	Solution s;
	int num = s.titleToNumber(str);
	cout<<num<<endl;
	system("pause");
}
