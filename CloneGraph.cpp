/*
*Word Break
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/

#include<iostream>
#include<vector>
#include <unordered_set>
#include<string.h>
#include<stdlib.h>

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL)
        	return NULL;
        map<UndirectedGraphNode*, UndirectedGraphNode*> copied;
		clone(node, copied);
       	return copied[node];
    }
    UndirectedGraphNode *clone(UndirectedGraphNode *node, map<UndirectedGraphNode*, UndirectedGraphNode*> copied) {
        if(node == NULL)
        	return NULL;
        if(copied.find(node) != copied.end()) 
        	return copied[node];
        UndirectedGraphNode * root = new UndirectedGraphNode(node->label);
       	vector<UndirectedGraphNode *> neighbors = node->neighbors;
       	copied[node] = root;
       	for(int i=0;i<neighbors.size(); i++){
       		UndirectedGraphNode * temp = neighbors[i];
       		UndirectedGraphNode * neighbor = cloneGraph(temp, copied);
       		root->neighbors.push_back(neighbor);
       	}
       	return root;
    }
};
