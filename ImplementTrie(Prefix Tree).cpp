/*
*Implement Trie (Prefix Tree)
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<map>
#include<sstream>
#include<math.h>
using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    bool iskey;
    TrieNode* childern[26];
    TrieNode() {
        for(int i=0;i<26;i++)
        	childern[i] = NULL;
        iskey = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        int len = word.size();
        TrieNode * node = root;
        char ch;
        for(int i=0;i<len;++i) {
        	ch = word[i];
			if(node->childern[ch - 'a'] == NULL)
				node->childern[ch - 'a'] = new TrieNode();
			if(i==len-1)
				node->childern[ch-'a']->iskey = true;
			node = node->childern[ch-'a'];
        }
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        int len = word.size();
        TrieNode * node = root;
        char ch;
        for(int i=0;i<len;++i){
        	ch = word[i];
        	if(node->childern[ch-'a'] == NULL)
        		return false;
        	if(i==len-1){
        		if(node->childern[ch-'a']->iskey == true)
        			return true;
        		else
        			return false;
        	}
			node = node->childern[ch-'a'];
        }
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        int len = prefix.size();
        TrieNode * node = root;
        char ch;
        for(int i=0;i<len;++i){
        	ch = prefix[i];
        	if(node->childern[ch-'a'] == NULL)
        		return false;
			node = node->childern[ch-'a'];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
