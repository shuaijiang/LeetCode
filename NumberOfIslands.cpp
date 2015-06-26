/*
*Number of Islands
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
    	int num = 0;
        for(int i=0;i<grid.size();++i){
        	for(int j=0;j<grid[i].size();++j){
        		if(isIsland(grid,i,j)){
        			num ++;
        		}
        	}
        }
        return num;
    }
    bool isIsland(vector<vector<char>>& grid, int i, int j){
    	if(i>=0 && i<grid.size() && j >=0 && j<=grid[i].size() && grid[i][j]=='1'){
    		grid[i][j]='_';
    		isIsland(grid,i-1,j);
    		isIsland(grid,i+1,j);
    		isIsland(grid,i,j-1);
    		isIsland(grid,i,j+1);
    		return true;
    	}
    	return false;
    }
};

