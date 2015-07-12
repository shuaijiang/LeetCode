/*
*Rotate Image
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
		for(int i=0;i<size/2;i++){
			//vector<int> row = matrix[i];
			for(int j=i;j<size-i-1;j++){
				int num = matrix[i][j];
				matrix[i][j] = matrix[size-j-1][i];
				matrix[size-j-1][i] = matrix[size-i-1][size-j-1];
				matrix[size-i-1][size-j-1] = matrix[j][size-i-1];
				matrix[j][size-i-1] = num;
			}
		}
		return;
    }
};
