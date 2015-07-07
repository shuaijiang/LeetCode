/*
*Power of Two
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/

#include<iostream>
#include<vector>
#include <unordered_set>
#include<string.h>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
        	return false;
        if(n==1)
        	return true;
		while(n>2&&n%2==0){
        	if(n%2==0)
        		n=n/2;
        	else
        		return false;
        }
        
        if(n%2==0)
        	return true;
        else
        	return false;
    }
};
