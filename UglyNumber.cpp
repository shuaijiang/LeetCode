/*
*Ugly Number
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    bool isUgly(int num) {
    	if(num == 0)
    		return false;
    	if(num == 1)
    		return true;
        if(num % 2 == 0){
        	if(num/2 == 0)
        		return true;
        	return isUgly(num/2);
        }
        	
        else if(num % 3 == 0){
        	if(num/3 == 0)
        		return true;
        	return isUgly(num/3);
        }
        else if(num % 5 == 0){
        	if(num/5 == 0)
        		return true;
        	return isUgly(num/5);
        }
        else 
    		return false;
    }
};

int main(){
	Solution s;
	int num = 14;
	bool result = s.isUgly(num);
	cout<<"Result="<<result<<endl;
	system("pause");
	return 0;
}
