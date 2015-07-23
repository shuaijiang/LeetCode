/*
*Search a 2D Matrix 2
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowSize = matrix.size();
        if(rowSize <= 0)
        	return false;
        vector<int> oneRow = matrix[0];
        int colSize = oneRow.size();
        if(colSize<=0)
        	return false;
        
        int coli = 0, colj = colSize -1;
        int maxCol;
        while(coli<=colj){
        	maxCol = colj;
        	int middle = (coli+colj)/2;
        	if(matrix[0][middle] == target)
        		return true;
        	else if(matrix[0][middle] < target)
        		coli = middle + 1;
        	else
        		colj = middle - 1;
        }
        
        for(int i=0;i<=maxCol;i++){
        	if(matrix[0][i]==target)
        		return true;
        	else if(matrix[0][i]<target){
        		int rowi=0, rowj=rowSize-1;
				while(rowi<=rowj){
					int middle = (rowi+rowj)/2;
					if(matrix[middle][i] == target)
		        		return true;
		        	else if(matrix[middle][i] < target)
		        		rowi = middle + 1;
		        	else
		        		rowj = middle - 1;
				}
        	}
        	else
        		break;
        }
        return false;
    }
};
