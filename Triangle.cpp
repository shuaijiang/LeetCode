/*
*Triangle 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
        vector<vector<int> > distance = triangle;
        int rowSize = distance.size();
        if(rowSize<=0)
        	return 0;
        if(rowSize == 1)
        	return distance[0][0];
        
        for(int i=1;i<rowSize;i++){
        	int colSize = i+1;
        	for(int j=0;j<colSize;j++){
        		if(j==0)
        			distance[i][j] += distance[i-1][0];
				else if(j==colSize-1) 
        			distance[i][j] += distance[i-1][j-1];
        		else
        			distance[i][j] += min(distance[i-1][j-1],distance[i-1][j]);
			}
        }
        int minTotal = distance[rowSize-1][0];
        int colSize = distance[rowSize-1].size();
		for(int i=1;i<colSize;i++){
        	if(distance[rowSize-1][i] < minTotal)
        		minTotal = distance[rowSize-1][i];
        }
        return minTotal;
    }
};

int main(){
	Solution s;
	vector<vector<int> > triangle;
	vector<int> oneRow;
	oneRow.push_back(-1);
	triangle.push_back(oneRow);
	oneRow.clear();
	oneRow.push_back(-2);
	oneRow.push_back(-3);
	triangle.push_back(oneRow);
	int total = s.minimumTotal(triangle);
	cout<<"total="<<total<<endl;
	
	system("pause");
	return 0;
}
