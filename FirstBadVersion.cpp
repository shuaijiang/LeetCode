/*
*First Bad Version 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version){
	//if(version >= 1702766719)
	if(version >= 2)
		return true;
	return false;
}

class Solution {
public:
    int firstBadVersion(int n) {
        double low = 1, high = n;
        double middle = 0;
        int m;
        while(low < high){
        	middle = (low + high) / 2;
        	m =  (int)floor(middle);
        	if(isBadVersion(m))
        		high = m;
        	else
        		low = m + 1;
        }
        if(low == high)
        	return low;
    }	
};

int main() {
	int n = 2; //2126753390;
	Solution s;
	int res = s.firstBadVersion(n);
	cout<<res<<endl;
	system("pause");
	return 0;
}
