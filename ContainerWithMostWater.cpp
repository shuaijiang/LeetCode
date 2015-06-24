/*
*Container With Most Water
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<map>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size()<=0)
        	return 0;
		vector<int>::iterator iter1,iter2;
		int count1,count2;
		int maxNum = 0, num = 0;
		iter1=height.begin();
		count1=0;
		iter2=height.end()-1;
		count2=height.size()-1;
        while(iter1<iter2){
        	num = (count2 - count1) * minOfTwoNum(*iter1,*iter2) ;
        	if(num > maxNum)
        		maxNum = num;
        	if(*iter1 < *iter2){
				iter1++;
				count1++;
        	}
        	else{
        		iter2--;
				count2--;	
        	}
        }
        return maxNum;
    }
    int minOfTwoNum(int x, int y){
    	if(x<y)
    		return x;
    	else
    		return y;
    }
};
