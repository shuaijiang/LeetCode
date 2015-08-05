/*
*Maximal Square
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rowNum = matrix.size();
        if(rowNum <= 0)
        	return 0;
        int colNum = matrix[0].size();
        vector<int> oneRow(colNum, 0);
        vector<vector<int>> dp;
        for(int i=0;i<rowNum;i++)
        	dp.push_back(oneRow);
    	int sideLength = 0;
    	// get the maximum side length
        for(int i=0;i<rowNum;i++){
        	for(int j=0;j<colNum;j++){
        		dp[i][j] = matrix[i][j] - '0';
        		if(i-1=>0 && j-1=>0 && dp[i][j]>0){
        			dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
        		}
        		if(dp[i][j] > sideLength)
        			sideLength = dp[i][j];
        	}
        }
        return sideLength * sideLength;
    }
};
