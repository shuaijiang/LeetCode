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
    int uniquePaths(int m, int n) {
        int matrix[100][100];
        matrix[0][0] = 1;
        for(int i=1;i<n;i++)
        	matrix[0][i]=1;
        for(int j=1;j<m;j++)
        	matrix[j][0] = 1;
        for(int i=1;i<m;i++){
        	for(int j=1;j<n;j++){
        		matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];
        	}
        }
        return matrix[m-1][n-1];
    }
};
