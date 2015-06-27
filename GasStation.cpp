/*
*Gas Station 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    	int i = 0, j = 0; 
        while(i<gas.size()){
        	j = i;
        	if(isCircuit(gas,cost,&j)){
        		return i;
        	}
			else if(i==j){
				i++;        		
        	}
        	else
        		i = j;
        }
        return -1;
    }
    bool isCircuit(vector<int>& gas, vector<int>& cost,int *i){
    	int gasLeft = 0;
    	int count = *i;
    	do{
    		gasLeft += gas[count] -cost[count];
    		if(gasLeft < 0){
    			*i = count+1;
    			return false;
    		}
    		count ++;
    		if(count == gas.size())
    			count = 0;
    	}while(count != *i);
    	
    	return true;
    }
};


//Method2: Time Limit Exceeded
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i=0;i<gas.size();++i){
        	if(isCircuit(gas,cost,i))
        		return i;
        }
        return -1;
    }
    bool isCircuit(vector<int>& gas, vector<int>& cost,int i){
    	int gasLeft = 0;
    	int count = i;
    	do{
    		gasLeft += gas[count] -cost[count];
    		if(gasLeft < 0)
    			return false;
    		count ++;
    		if(count == gas.size())
    			count = 0;
    	}while(count != i);
    	return true;
    }
};
