/*
*Add Binary
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        vector<char> result;
        string str;
		int sizeA = a.size();
        int sizeB = b.size();
        int countA = sizeA-1, countB = sizeB-1; 
        int Add = 0;
        
		while(countA>=0 && countB>=0){
			int num = a[countA]-'0' + b[countB]-'0';
			
			if(Add == 1){
				num++;
				Add = 0; 
			}
			
			if(num==2){
				Add = 1;
				num = 0;
			}
			else if(num==3){
				Add = 1;
				num = 1;
			}
			result.push_back(num + '0');
			countA--;
			countB--;
		}
        while(countA>=0){
        	int num = a[countA] - '0';
			if(Add == 1){
        		num++;
        		Add = 0;
        	}
        	if(num == 2){
        		Add = 1;
        		num = 0;
        	}
        	result.push_back(num + '0');
			countA--;
        }
        while(countB>=0){
        	int num = b[countB] - '0';
			if(Add == 1){
        		num++;
        		Add = 0;
        	}
        	if(num == 2){
        		Add = 1;
        		num = 0;
        	}
        	result.push_back(num + '0');
			countB--;
        }
        if(Add == 1)
        	result.push_back('1');
        for(int i=result.size()-1;i>=0;i--)
        	str.push_back(result[i]);
        
        return str;
    }
};
