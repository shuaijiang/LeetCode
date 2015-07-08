/*Pascal's Triangle 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(numRows <= 0)
        	return result;
        vector<int> oneRow;
        oneRow.push_back(1);
        result.push_back(oneRow);
        if(numRows == 1)
        	return result;
        	
        for(int i=1;i<numRows;i++){
        	vector<int> row;
        	int num = 0;
        	row.push_back(1);
        	for(int j=1;j<i;j++){
        		num = result[i-1][j-1] + result[i-1][j];
        		row.push_back(num);
        	}
        	row.push_back(1);
        	result.push_back(row);
        }
        return result;
    }
};
