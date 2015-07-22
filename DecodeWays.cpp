/*
*Decode Ways
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int size = s.size();
		vector<int> nums(size, 0);
        if(size<=0)
        	return 0;
    	
		if(s[0]=='0')
    		return 0;
    	else
    		nums[0] = 1;
        
		if(size==1)
			return nums[size-1];
        
        if(s[1]=='0'){
			if(s[0] <= '2')
				nums[1] = 1;
			else
				return 0;
        }
        else{
        	if(s[0] == '1') nums[1] = 2;
	        if(s[0] == '2'){
	        	if(s[1] <= '6') 
					nums[1]=2;
	        	else
					nums[1] = 1;
	        }
			if(s[0] >= '3') nums[1] = 1;
        }
        
		for(int i=2;i<size;i++){
			if(s[i] == '0'){
				nums[i] = nums[i-2];
				if(s[i-1] >= '3' || s[i-1] <= '0')
					return 0;
			}
			else{
				if(s[i-1] == '1')
					nums[i] = nums[i-1] + nums[i-2];
				else if(s[i-1] == '2') {
					if(s[i] <= '6')
						nums[i] = nums[i-1] + nums[i-2];
					else
						nums[i] = nums[i-1];
				}
				else{
					nums[i] = nums[i-1];
				}
			}
		}
		return nums[size-1];
    }
};
