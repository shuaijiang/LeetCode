/*Implement Stack using Queues 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<queue>
#include<stdlib.h>

class Stack {
public:
	queue<int> myQueue;
    // Push element x onto stack.
    void push(int x) {
        myQueue.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        queue<int> queue2;
        int num;
        while(myQueue.size() > 1){
        	num = myQueue.front();
        	myQueue.pop();
        	queue2.push(num);
        }
        myQueue = queue2;
    }

    // Get the top element.
    int top() {
        return myQueue.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return myQueue.empty();
    }
};
