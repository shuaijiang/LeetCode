/*
*Happy Number
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<string.h>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
    	map<int,int> myMap;
    	myMap[n] = 1;
        while(n!=1){
        	n = squareSum(n);
        	if(n == 1)
        		break;
        	if(myMap.find(n)==myMap.end()){
        		myMap[n] = 1;
        	}
        	else{
        		return false;
        	}
        }
        return true;
    }
    int squareSum(int n){
    	vector<int> vec;
    	int elem = 0, sum = 0;
    	
    	while(n>0){
    		elem = n % 10;
    		vec.push_back(elem);
    		n = n / 10;
    	}
    	for(int count=0;count<vec.size();++count){
    		sum += vec[count] * vec[count];
    	}
    	return sum;
    }
};
