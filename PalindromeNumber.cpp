/*
*Palindrome Number  
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
    	if(x < 0)
    		return false;
    	int y = x;
		int len = numberLength(y);
		if(len == 1)
			return true;
		int high_num, low_num;
		int high_divisor, low_divisor;
		high_divisor = pow(10,len-1);
		low_divisor  = 10;
		while(high_divisor >= low_divisor){
			high_num = y / high_divisor;
			low_num  = y % low_divisor; 
			if(high_num != low_num)
				return false;
			y = y - high_num * high_divisor;
			y = y / low_divisor;
			high_divisor = high_divisor / 100;
		}
		
		return true;
    }
    int numberLength(int x){
    	int y = x;
		int len = 0;
		while(y>0){
			y = y / 10;
			len ++;
		}
		return len;
    }
};
//the code under below is for test
int main(){
	Solution s;
	int x = -2147447412;
	int len = s.numberLength(x);
	bool p = s.isPalindrome(x);
	cout<<"len="<<len<<endl;
	cout<<"p="<<p<<endl;
	system("pause");
	return 0;
}
