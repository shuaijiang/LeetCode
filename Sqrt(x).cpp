/*Sqrt(x) 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
    	if(x <= 0)
    		return -1;
        if(x == 1)
        	return 1;
        
        int low  = 1;
        int high = x/2+1;
        int mid;
        while(low<=high){
        	mid = (low+high)/2;
			 
        	if(mid <= x/mid  && (mid+1) > x/(mid+1))
        		return mid;
        	else if(mid > x/mid)
        		high -= 1;
        	else
        		low += 1;
        }
        return -1;
    }
};
