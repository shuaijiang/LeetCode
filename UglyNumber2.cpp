/*
*Ugly Number2
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
    	if(n <= 0)
    		return -1;
    	if(n == 1)
    		return 1;
        int n1 = 0, n2 = 0, n3 = 0;
		vector<int> L1, L2, L3;
		L1.push_back(2);
		L2.push_back(3);
		L3.push_back(5);
		int num = 1;
		for(int count=2;count<=n;count++){
			int minNum=min(L1[n1],min(L2[n2],L3[n3]));
			
			L1.push_back(minNum * 2);
			L2.push_back(minNum * 3);
			L3.push_back(minNum * 5);
			
			if(L1[n1] == minNum)
				n1 ++;
			if(L2[n2] == minNum)
				n2 ++;
			if(L3[n3] == minNum)
				n3 ++;
			num = minNum;
			//cout<<num<<endl;
		}
		return num;
    }
};

int main()
{
	Solution s;
	int num = s.nthUglyNumber(12);
	cout<<"num="<<num<<endl;
	system("pause");
	return 0;
}
