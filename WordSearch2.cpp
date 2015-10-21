/*
*Word Search II 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
using namespace std;
/*
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
		int rowNum = board.size();
        if(rowNum <= 0)
        	return result;
        int colNum = board[0].size();
        
        for(int count=0;count<words.size();count++){
        	vector<vector<bool>> visit(rowNum, vector<bool>(colNum,false));
        	string word = words[count];
			for(int i=0;i<rowNum;i++){
				for(int j=0;j<colNum;j++){
					if(board[i][j] == word[0]){
						if(same(board,visit,i,j,word,0))
							result.push_back(word);
					}
				}
			}
        }
		return result;
    }
    bool same(vector<vector<char>> &board, vector<vector<bool>> &visit, int i, int j, string word, int index){
    	if(index == word.size()-1){
			if(board[i][j] == word[index] && visit[i][j] == false)
				return true;
			else
				return false;
		} 
		else{
			if(board[i][j] == word[index])
				visit[i][j] = true;
			else
				return false;
			bool flag = false;
			if(i>0 && visit[i-1][j] == false){
				flag = flag || same(board, visit, i-1, j, word, index+1);
			}
				
			if(i<board.size()-1 && visit[i+1][j] == false){
				flag = flag || same(board, visit, i+1, j, word, index+1);
			}
				
			if(j>0 && visit[i][j-1] == false){			
				flag = flag || same(board, visit, i, j-1, word, index+1);
			}
				
			if(j<board[0].size()-1 && visit[i][j+1] == false){
				flag = flag || same(board, visit, i, j+1, word, index+1);
			}
			visit[i][j] = false;
			return flag;
		}
    }
};
*/

class TrieNode{
public:	
	bool iskey;
	TrieNode * childern[26];
	TrieNode(){
		iskey = false;
		for(int i=0;i<26;++i){
			childern[i] = NULL;
		}
	}
};
class Solution {
public:
	vector<string> res;
	int row;
	int col;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        
        int wordNum = words.size();
        if(wordNum <= 0)
        	return res;
        
		row = board.size();        
        col = board[0].size();
        
        //create tried tree 
        for(int i=0;i<wordNum;++i){
        	string word = words[i];
        	int wordLen = word.size();
        	TrieNode * node = root;
        	char ch;
        	for(int j=0;j<wordLen;++j){
        		ch = word[j];

				if(node->childern[ch - 'a'] == NULL){
        			node->childern[ch - 'a'] = new TrieNode() ;
        		}
        		if(j == wordLen-1){
        			node->childern[ch - 'a']->iskey = true;
        		}
        		node =  node->childern[ch-'a'];
        		
        	}
        }
        // find the words in the board
        
        for(int i=0;i<row;i++){
        	for(int j=0;j<col;j++){
        		vector<vector<bool>> path(row, vector<bool>(col, false));
				char ch = board[i][j];
				if(root->childern[ch-'a'] != NULL)
					find(board, path, i, j, root, "");
        	}
        }
        return res;
    }
    void find(vector<vector<char>>& board, vector<vector<bool>> &path, int i, int j, TrieNode *node, string str){
    	if(i<0 || i>=row || j< 0 || j>=col)
    		return;
    	if(path[i][j])
    		return ;
    	char ch = board[i][j];
    	node = node->childern[ch-'a'];
    	if(node == NULL)
    		return;

    	str.push_back(ch);
    	if(node->iskey){
    		res.push_back(str);
    		node->iskey = false;
    	}
    	
    	path[i][j] = true;
    	if(i-1>=0 && i-1<row)
    		find(board, path, i-1, j, node, str);
    	if(i+1>=0 && i+1<row)
			find(board, path, i+1, j, node, str);
    	if(j-1>=0 && j-1<col)
		find(board, path, i, j-1, node, str);
    	if(j+1>=0 && j+1<col)
			find(board, path, i, j+1, node, str);
			
		path[i][j] = false;
		
    	
    }
private:
	TrieNode * root;
};

int main(){
	Solution s;
	vector<vector<char>> board(1,vector<char>(2,'a'));
	vector<string> words(1,"a");
	vector<string> res = s.findWords(board, words);
	cout<<"res.size"<<res.size();
	/*
	for(int i=0;i<res.size();++i){
		cout<<res[i]<<endl;
	}*/
	return 0;

}
