/*
*Climbing Stairs  
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {    		
    	vector<int> vec;
		vec.push_back(1);
		vec.push_back(1);
        if(n<=1)
        	return vec[n];
        for(int i=2;i<=n;i++){
        	int num = vec[i-1] + vec[i-2];
        	vec.push_back(num);
        }
        return vec[n];
    }
};
//The code below is used for test
int main()
{
	int n = 44;
	Solution s;
	int result = s.climbStairs(n);
	cout<<"result="<<result<<endl;
	system("pause");
	return 0;
}
