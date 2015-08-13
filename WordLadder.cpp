/*
*Word Ladder
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        map<string, int> wordVisited;
        queue<string> curr, next;
        bool found = false;
        int len = 0;
        curr.push(beginWord);
        while(!curr.empty() && !found){
        	len ++;
        	while(!curr.empty() && !found){
        		string str = curr.front();
        		curr.pop();
        		for(int i=0;i<str.size();i++){
        			for(char ch='a';ch<='z';ch++){
        				if(ch == str[i])
        					continue;
        				swap(ch, str[i]);
        				if(str == endWord){
        					found = true;
        					break;
        				}
        				if(wordDict.count(str)>0 && wordVisited.find(str) == wordVisited.end()){
        					wordVisited[str] = 1;
        					next.push(str);
        				}
        				
        				swap(str[i], ch);
        			}
        		}
        	}
        	swap(curr,next);
        }
        if(found)
        	return len+1;
        else
        	return 0;
    }
};
