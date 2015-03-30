/*
*Factorial Trailing Zeroes
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) 
	{
        int zeros = 0;
		int factor = 5;
        while(n)
        {
			
			zeros = zeros + n/factor;
			n = n/factor;
        }
		return zeros;
	}
	/* The code below exceed the time
    int trailingZeroes(int n) 
	{
        int zeros = 0;
		int factor = 5;
        while(factor <= n)
        {
		
			zeros = zeros + n/factor;
			factor = factor * 5;
			if(factor >= 2147483647)
				return zeros;
        }
		return zeros;
	}
	*/
};

int main()
{

	Solution s;
	int n = 2147483647;
	cout<<"n="<<n<<endl;
	int zeros = s.trailingZeroes(n);
	cout<<zeros<<endl;
	system("pause"); 
}
