/*
*Minimum Path Sum
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<math>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rowSize = grid.size();
        if(rowSize<=0)
        	return 0;
        vector<int> oneRow = grid[0];
        int colSize = oneRow.size();
        
        int **matrix = new int*[rowSize];
        for(int i=0;i<rowSize;i++){
        	matrix[i] = new int[colSize];
        	for(int j=0;j<colSize;j++)
        		matrix[i][j] = 0;
        }
    	matrix[0][0] = grid[0][0];
    	for(int i=1;i<colSize;i++)
        	matrix[0][i] = matrix[0][i-1] + grid[0][i];
        for(int i=1;i<rowSize;i++)
        	matrix[i][0] = matrix[i-1][0] + grid[i][0];
        
        for(int i=1;i<rowSize;i++){
        	for(int j=1;j<colSize;j++){
        		matrix[i][j] = grid[i][j] + min(matrix[i-1][j],matrix[i][j-1]);
        	}
        }
        return matrix[rowSize-1][colSize-1];
    }
};
