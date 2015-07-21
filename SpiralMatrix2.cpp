/*
*Spiral Matrix 2
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    vector< vector<int> > generateMatrix(int n) {
        vector< vector<int> > matrix;
        vector<int> oneRow; 
		if(n<=0)
        	return matrix;
        for(int i=0;i<n;i++)
        	oneRow.push_back(0);
        for(int i=0;i<n;i++)
        	matrix.push_back(oneRow);
        
        int rowBegin=0, rowEnd=n-1;
        int colBegin=0, colEnd=n-1;
        int num = 1;
        while(rowBegin<rowEnd && colBegin<colEnd){
        	for(int i=colBegin;i<colEnd;i++){
        		matrix[rowBegin][i] = num++;
        		
        	}
        		
        	for(int i=rowBegin;i<rowEnd;i++)
        		matrix[i][colEnd] = num++;
        	for(int i=colEnd;i>colBegin;i--)
        		matrix[rowEnd][i] = num++;
        	for(int i=rowEnd;i>rowBegin;i--)
        		matrix[i][colBegin] = num++;
        	rowBegin ++; rowEnd --;
        	colBegin ++; colEnd --;
        }
        if(rowBegin == rowEnd && colBegin == colEnd){
        	matrix[rowBegin][colBegin] = num;
		}
		return matrix;	 
	}
};
//The code under below is used for test
int main(){
	Solution s;
	int n=2;
	vector< vector<int> > matrix = s.generateMatrix(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<matrix[i][j]<<" ";
		cout<<endl;
	}
	
	system("pause");
	return 0;
}
