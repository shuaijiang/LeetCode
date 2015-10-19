/*
*Bitwise AND of Numbers Range
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = m;
        if(m==0)
            return 0;
		int move = 0; // the number of the move steps
        while(m!=n){
            m = m>>1;
            n = n>>1;
            move +=1;
        }
        return m << move;  // if m is 0, then the result is also 0
    }
};
int main(){
	Solution s;
	//int m = 600000000, n = 2147483645;
	int m = 2147483646, n = 2147483647;
	int res = s.rangeBitwiseAnd(m, n);
	cout<<res<<endl;
	return 0;
}
