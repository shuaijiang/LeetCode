/*
*Gray Code
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<math>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
		if(n<0)
			return result;
		
		result.push_back(0);
		if(n==0)
			return result;
		result.push_back(1);
		if(n==1)
			return result;
		
		for(int i=2;i<=n;i++){
			int size = result.size();
			int addNum = pow(2,i-1);
			for(int j=size-1;j>=0;j--){
				int num = result[j] + addNum;
				result.push_back(num);
			}
		}
		return result;
    }
};
