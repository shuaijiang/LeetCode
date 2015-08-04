/*
*Best Time to Buy and Sell Stock III
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size<=0)
        	return 0;
        vector<int> currProfit(size,0);
        int maxPro = 0;
        int result=0;
        int minPrice = prices[0];
        for(int i=1;i<size;i++){
        	minPrice = min(prices[i-1], minPrice);
        	if((prices[i]-minPrice) > maxPro)
        		maxPro = prices[i] - minPrice;
			currProfit[i] = maxPro;
        }
        maxPro = 0;
        int maxPrice = prices[size-1];
        for(int i=size-2;i>=0;i--){
        	maxPrice = max(prices[i+1], maxPrice);
			if((maxPrice - prices[i]) > maxPro)
				maxPro = maxPrice - prices[i];
			if(maxPro + currProfit[i] > result)
				result = maxPro + currProfit[i];
        }
        return result;
    }
};

int main(){
	Solution s;
	vector<int> prices;
	prices.push_back(6); 
	prices.push_back(1);
	prices.push_back(3);
	prices.push_back(2);
	prices.push_back(4);
	prices.push_back(7);
	
	int res = s.maxProfit(prices);
	cout<<"res="<<res<<endl;
	system("pause");
	return 0;
}
