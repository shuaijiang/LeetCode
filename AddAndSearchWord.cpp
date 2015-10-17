/*
*Add and Search Word 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<map>
using namespace std;
class TrieNode{
public:
	bool iskey;   // 标记该节点是否代表关键字
    TrieNode *children[26]; // 各个子节点
    TrieNode() {
        iskey = false;
        for(int i=0; i<26; ++i)
            children[i] = NULL;
    }
}; 
class WordDictionary {
public:
	WordDictionary(){
		root =  new TrieNode();	
	}
    // Adds a word into the data structure.
    void addWord(string word) {
        int len = word.size();
        if(len <= 0)
        	return ;
        TrieNode *node = root; 
        for(int i=0;i<len;++i){
        	char ch = word[i];
        	if(node->children[ch-'a'] == NULL) {
        		node->children[ch-'a'] = new TrieNode();
        	}
        	node = node->children[ch-'a'];        	
        }
        node->iskey = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        int len = word.size();
        if(len <= 0)
        	return false;
        
        return dfs(root, word, 0);
    }
    bool dfs(TrieNode* node, string word, int i){
    	int len = word.size();
    	if(i >= len)
    		return false;
		char ch = word[i];
    	if(ch != '.'){
    		if(node->children[ch-'a'] == NULL){
    			return false;
    		}
    		else{
    			if(i == len-1){
    				if(node->children[ch-'a']->iskey == true)
    					return true;
    				else
    					return false;
    			}
    			return dfs(node->children[ch-'a'], word, i+1);
    		}
    	}
    	else{
    		for(int j=0;j<26;j++){
    			if(node->children[j] != NULL){
    				if(i == len -1){
    					if(node->children[j]->iskey)
							return true;
						else
							continue;
    				}
    				if(dfs(node->children[j], word, i+1))
    					return true;
    			}
    		}
    	}
    }
private:
	TrieNode * root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
int main(){
	WordDictionary wd;
	wd.addWord("abc");
	wd.addWord("hello");
	
	if(wd.search("ab."))
		cout<<"Get ab."<<endl;
	if(wd.search("abd"))
		cout<<"Get ab."<<endl;
	
	return 0;
}
