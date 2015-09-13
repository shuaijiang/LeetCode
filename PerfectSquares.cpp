/*
*Perfect Squares
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<math.h>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
    	if(n <= 0)
    		return -1;
    	if(n == 1)
    		return 1;
        vector<int> square;
        vector<int> nums;
        nums.push_back(0);
        nums.push_back(1);
        int num = 1;
		while(num*num <= n){
			square.push_back(num*num);
			num ++;
		}
		
		int index = 0;
		for(int i=2;i<=n;i++){
			index = sqrt(i);
			int factor = square[index-1];
			if(factor == i) {
				nums.push_back(1);
				continue;
			}
			int minCount = nums[i-factor] + 1;
			for(int j=index-2;j>=0;j--){
				factor = square[j];
				int count = nums[i - factor] + 1;
				minCount = min(minCount, count);
			}
			cout<<i<<" "<<minCount<<endl;
			nums.push_back(minCount);			
		}
		return nums[n];
    }
};
int main(){
	Solution s;
	int n = 100;
	int result = s.numSquares(n);
	cout<<"result="<<result<<endl;
	system("pause");
	return 0;
}

