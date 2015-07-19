/*
*Search a 2D Matrix  
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowSize = matrix.size();
        if(rowSize <= 0)
        	return false;
        vector<int> oneRow = matrix[0];
        int colSize = oneRow.size();
        int rowTarget = -1;
        for(int i=0;i<rowSize;i++){
        	if(target <= matrix[i][colSize-1]){
        		rowTarget = i;
        		break;
        	}
        }
    	if(rowTarget == -1)
    		return false;
    	for(int i=0;i<colSize;i++){
    		if(target == matrix[rowTarget][i]){
    			return true;
    		}
    	}
    	return false;
    }
};
