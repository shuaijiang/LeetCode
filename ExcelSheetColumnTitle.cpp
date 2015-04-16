/*
*Excel Sheet Column Title 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<sstream>

using namespace std;

class Solution {
public:
	string convertToTitle(int n) {
    	string str;
    	stringstream ss;
    	char chA = 'A';
		while(n>0)
		{
			n = n - 1; 
			int remain = n % 26;
			char ch;
			n = n / 26;
				
			ch = chA + remain ;				

			string oneStr;
			ss.clear();
			ss<<ch;
			ss>>oneStr;
			str.append(oneStr);
		}
		
		string s(str.rbegin(),str.rend());
		return s;
    }
}; 

int main()
{
	
	int num = 52;
	Solution s;
	string str = s.convertToTitle(num);
	cout<<str<<endl;
	system("pause");
}
