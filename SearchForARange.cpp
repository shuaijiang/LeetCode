/*
*Search for a Range
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> notfound, result;
        notfound.push_back(-1);
        notfound.push_back(-1);
        result.push_back(0);
        result.push_back(0);
        
        int size = nums.size();
        if(size <= 0)
        	return notfound;
        if(size == 1 && nums[0] == target)
        	return result;
        
		int begin=0, end= size-1, middle=0;
		bool isfind = false;
		int index = 0;
		while(begin <= end){
			if(begin == end){
				if(nums[begin] != target)
					return notfound;
				else{
					isfind = true;
					index = begin;
				}	
				break;
			}
			middle = (begin + end) / 2;
			if(nums[middle] == target){
				isfind = true;
				index = middle;
				break;
			}
			else if(nums[middle] < target)
				begin = middle + 1;
			else
				end = middle - 1;
		}
		if(isfind){
			int i = index-1;
			
			while(i>=0 && nums[i]==target)
				i--;
			
			begin = i+1;
			i = index + 1;
			while(i<size && nums[i]==target)
				i++;
			end = i - 1;
			
			result[0] = begin;
			result[1] = end;
			return result;
		}
		else
			return notfound; 
    }
};

int main(){
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(3);
	
	vector<int> result = s.searchRange(nums, 1);
	for(int i=0;i<result.size();i++)
		cout<<result[i]<<endl;
		
	system("pause");
	return 0;
}
