/*
*Trapping Rain Water 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if(size<=1) 
        	return 0;
        int left=0, right=size-1;
        int area = 0, secondH = 0;
        while(left < right){
        	if(height[left] < height[right]){
        		secondH = max(height[left], secondH);
        		area += secondH - height[left];
        		left ++;
        	}
        	else{
        		secondH = max(height[right],secondH);
        		area += secondH - height[right];
        		right --;
        	}
        }
        return area;
    }
};
