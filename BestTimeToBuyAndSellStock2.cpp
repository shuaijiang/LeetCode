/*Best Time to Buy and Sell Stock II
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
       if(prices.size()<=0)
       	return 0;
	   int profit = 0;

	   for(int i=1;i<prices.size();i++){
	   		int diff = prices[i]-prices[i-1];
	   		if(diff>=0)
	   			profit += diff;
	   }
	   		
	   	return profit;
    }
};
