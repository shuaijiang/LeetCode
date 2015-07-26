/*
*String To Integer
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        double result = 0.0;
        int flag = 1, work = 0;
		int size = str.size(), i = 0;
		while(str[i] == ' ')
			i++;
		if(str[i] == '-'){
			i ++;
			flag = 0;
		}
		else if(str[i] == '+')
		{
			i++;
			flag = 1;
		}
		
		for(;i<size;i++){
			if(str[i]>='0' && str[i]<='9'){
				result = result * 10 + (str[i] - '0');
				work = 1;
			}
			else
				break;
		}
		if(work == 0)
			return 0;
		if(flag == 1 && result  >= INT_MAX)
			return INT_MAX;
		if(flag == 0 && result > INT_MAX)
			return INT_MIN;
		
		int myInt = (int) result;
		if(flag == 0)
			myInt = -1 * myInt;
		return myInt;
    }
};
