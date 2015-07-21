/*
*Spiral Matrix 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowBegin, rowEnd;
		int colBegin, colEnd;
		vector<int> result;
		int rowSize = matrix.size();
		if(rowSize<=0)
			return result;
			
		int colSize = matrix[0].size();
		if(colSize<=0)
			return result;
		
		rowBegin = 0; rowEnd = rowSize-1;
		colBegin = 0; colEnd = colSize-1;
		while(rowBegin<rowEnd && colBegin<colEnd) {
			for(int i=colBegin;i<colEnd;i++)
				result.push_back(matrix[rowBegin][i]);
			for(int i=rowBegin;i<rowEnd;i++)
				result.push_back(matrix[i][colEnd]);
			for(int i=colEnd;i>colBegin;i--)
				result.push_back(matrix[rowEnd][i]);
			for(int i=rowEnd;i>rowBegin;i--)
				result.push_back(matrix[i][colBegin]);
			rowBegin ++; rowEnd --;
			colBegin ++; colEnd --;
		}
		if(rowBegin == rowEnd && colBegin == colEnd)
			result.push_back(matrix[rowBegin][colBegin]);
		else{
			if(rowBegin == rowEnd){
				for(int i=colBegin;i<=colEnd;i++)
					result.push_back(matrix[rowBegin][i]);
			}
			if(colBegin == colEnd){
				for(int i=rowBegin;i<=rowEnd;i++)
					result.push_back(matrix[i][colBegin]);
			}
		}
		return result;
    }
};
