/*
*Set Matrix Zeroes 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowSize = matrix.size();
        if(rowSize<=0)
        	return;
        bool firstRow=false, firstCol=false;
        vector<int> oneRow = matrix[0];
        int colSize = oneRow.size();
        
		for(int i=0;i<colSize;i++){
        	if(matrix[0][i]==0)
        		firstRow = true;
        }

        for(int i=0;i<rowSize;i++){
        	if(matrix[i][0]==0)
        		firstCol = true;
        }
        
        for(int i=1;i<rowSize;i++){
        	for(int j=1;j<colSize;j++){
        		if(matrix[i][j]==0){
        			matrix[i][0]=0;
        			matrix[0][j]=0;
        		}
        	}
        }
        //Set rows to zeros
        for(int i=1;i<rowSize;i++){
        	if(matrix[i][0]==0){
        		for(int j=1;j<colSize;j++)
        			matrix[i][j] = 0;
        	}
        }
        //Set columns to zeros
        for(int i=1;i<colSize;i++){
        	if(matrix[0][i]==0){
        		for(int j=1;j<rowSize;j++)
        			matrix[j][i] = 0;
        	}
        }
        //Set first row to zeros
        if(firstRow){
        	for(int i=0;i<colSize;i++)
        		matrix[0][i]=0;
        }
        //Set first column to zeros
        if(firstCol){
        	for(int i=0;i<rowSize;i++)
        		matrix[i][0] = 0;
        }
    }
};
