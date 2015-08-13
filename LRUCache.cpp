/*
*LRU Cache
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<stack>
#include<stdlib.h>
using namespace std;

class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cacheMap.find(key) == cacheMap.end())
        	return -1;
        
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        cacheMap[key] = cacheList.begin();
        return cacheMap[key]->value;
    }
    
    void set(int key, int value) {
        if(cacheMap.find(key) == cacheMap.end()){
        	if(capacity == cacheList.size()){
        		cacheMap.erase(cacheList.back().key);
        		cacheList.pop_back(); 
        	}
        	CacheNode node(key,value);
        	cacheList.push_front(node);
        	cacheMap[key] = cacheList.begin();
        }
        else{
        	cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        	cacheMap[key] = cacheList.begin();
        	cacheMap[key]->value = value;
        }
        
    }
private:
	struct CacheNode{
		int key;
		int value;
		CacheNode(int k, int v):key(k), value(v){}
	};
	int capacity;
	list<CacheNode> cacheList;
	map<int, list<CacheNode>::iterator> cacheMap;
};
