/*
*Best Time to Buy and Sell Stock 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size<=0)
        	return 0;
        int maxPro = 0, profit=0;
        int start=0, end=0;
        for(int i=1;i<size;i++){
        	profit = prices[i] - prices[start];
        	if(maxPro < profit)
        		maxPro = profit; 
			if(profit <= 0)
				start = i;
        }
        return maxPro;
    }
};
