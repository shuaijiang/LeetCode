/*Implement Queue using Stacks
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<stack>
#include<stdlib.h>
using namespace std;
class Queue {
public:
	stack<int> stack1,stack2;
    // Push element x to the back of queue.
    void push(int x) {
        stack1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(!stack2.empty())
        	stack2.pop();
        else{
        	Stack1ToStack2();
        	stack2.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        if(!stack2.empty())
        	return stack2.top();
        else{
        	Stack1ToStack2();
        	return stack2.top();
        }
    }

    // Return whether the queue is empty.
    bool empty(void) {
        if(stack1.empty()&&stack2.empty())
        	return true;
        else
        	return false;
    }
    void Stack1ToStack2(){
    	if(!stack2.empty())
    		return;
    	while(!stack1.empty()){
    		int num = stack1.top();
    		stack1.pop();
    		stack2.push(num);
    	}
    }
};
