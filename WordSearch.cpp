/*
*Word Search
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rowNum = board.size();
        if(rowNum <= 0)
        	return false;
        int colNum = board[0].size();
        vector<vector<char>> myBoard = board;
		for(int i=0;i<rowNum;i++){
			for(int j=0;j<colNum;j++){
				if(board[i][j] == word[0]){
					myBoard = board;
					if(same(myBoard,i,j,word,0))
						return true;
				}
			}
		}
		return false;
    }
    bool same(vector<vector<char>> &board, int i, int j, string word, int index){
    	if(index == word.size()-1){
			if(board[i][j] == word[index])
				return true;
			else
				return false;
		} 
		else{
			if(board[i][j] == word[index])
				board[i][j] = '_';
			else
				return false;
			bool flag = false;
			if(i>0){
				vector<vector<char>> myBoard = board;
				flag = flag || same(myBoard, i-1, j, word, index+1);
			}
				
			if(i<board.size()-1){
				vector<vector<char>> myBoard = board;
				flag = flag || same(myBoard, i+1, j, word, index+1);
			}
				
			if(j>0){
				vector<vector<char>> myBoard = board;
				flag = flag || same(myBoard, i, j-1, word, index+1);
			}
				
			if(j<board[0].size()-1){
				vector<vector<char>> myBoard = board;
				flag = flag || same(myBoard, i, j+1, word, index+1);
			}
				
			return flag;
		}
    }
};
