/*
*Unique Paths 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int matrix[100][100];
        int rowSize=obstacleGrid.size();
        if(rowSize<=0)
        	return 0;
        vector<int>oneRow = obstacleGrid[0];
        int colSize = oneRow.size();
        if(obstacleGrid[0][0]==0)
        	matrix[0][0] = 1;
        else
        	matrix[0][0] = 0;
        for(int i=1;i<colSize;i++){
        	if(obstacleGrid[0][i]==1)
        		matrix[0][i] = 0;
        	else
        		matrix[0][i] = matrix[0][i-1];
        }
        for(int j=1;j<rowSize;j++){
        	if(obstacleGrid[j][0]==1)
        		matrix[j][0] = 0;
        	else
        		matrix[j][0] = matrix[j-1][0];
        }
        
        for(int i=1;i<rowSize;i++){
        	for(int j=1;j<colSize;j++){
        		if(obstacleGrid[i][j]==1)
        			matrix[i][j] = 0;
        		else
        			matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];
        	}
        }
        return matrix[rowSize-1][colSize-1];
    }
};
