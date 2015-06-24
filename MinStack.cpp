/*
*Min Stack 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class MinStack {
public:
	vector<int> stack;
	vector<int> minStack;
	vector<int>::iterator iter, minIter;
	vector<int>::reverse_iterator reiter;
    void push(int x) {
        stack.push_back(x);
        if(minStack.size()<1)
        	minStack.push_back(x);
        else{
        	reiter = minStack.rbegin();
        	if(x <= *reiter)
        		minStack.push_back(x);
        }
    }

    void pop() {
    	if(stack.size() < 1)
			return ; 
        reiter = stack.rbegin();
        int num = * reiter;
        reiter = minStack.rbegin();
        int minNum = *reiter;
        
        stack.pop_back();
        if(num == minNum){
        	minStack.pop_back();
        }
    }

    int top() {
        reiter = stack.rbegin();
        return *reiter;
    }

    int getMin() {
        reiter = minStack.rbegin();
        return *reiter;
    }
};
