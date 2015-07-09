/*Pascal's Triangle II 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> lastRow;
		vector<int> row;
        if(rowIndex < 0)
        	return row;

        lastRow.push_back(1);

        if(rowIndex == 0)
        	return lastRow;
        	
        for(int i=1;i<=rowIndex;i++){
        	int num = 0;
        	row.push_back(1);
        	for(int j=1;j<i;j++){
        		num = lastRow[j-1] + lastRow[j];
        		row.push_back(num);
        	}
        	row.push_back(1);
        	lastRow = row;
        	row.clear();
        }
        return lastRow;
    }
};
