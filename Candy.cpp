/*
*Candy  
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies;
        int size = ratings.size();
        for(int i=0;i<size;i++)
        	candies.push_back(1);
        for(int i=1;i<size;i++){
        	if(ratings[i] > ratings[i-1])
        		candies[i] = candies[i-1] + 1;
        }
        for(int i=size-2;i>=0;i--){
        	if(ratings[i] > ratings[i+1] && candies[i] <= candies[i+1])
        		candies[i] = candies[i+1] + 1;
        }
        int result = 0;
        for(int i=0;i<size;i++)
        	result += candies[i];
        return result;
    }
};
