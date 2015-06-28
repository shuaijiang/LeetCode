/*
*Valid Sudoku
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row=0;row<board.size();row++){
        	if(!isValid(board,row,row,0,board[row].size()-1))
        		return false;
        }
        for(int col=0;col<board[0].size();col++){
        	if(!isValid(board,0,board.size()-1,col,col))
        		return false;
        }
        for(int row=0;row<board.size();row+=3){
        	for(int col=0;col<board[0].size();col+=3){
        		if(!isValid(board,row,row+2,col,col+2))
        			return false;
        	}
        }
        return true;
    }
    bool isValid(vector<vector<char>>& board, int rowi, int rowj, int coli, int colj) {
    	int index[10]={0};
    	int num;
    	for(int row=rowi;row<=rowj;row++){
    		for(int col=coli;col<=colj;col++){
    			if(board[row][col]!='.'){
    				num = board[row][col] - '0';
    				index[num] += 1;
    				if(index[num] > 1)
    					return false;
    			}
    		}
    	}
    	return true;
    }
};
