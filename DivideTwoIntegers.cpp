#include<iostream>
#include<math.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        int res  = 0, move = 0;
        int MIN_VALUE = -2147483648;
        int MAX_VALUE = 2147483647;
        if(divisor == 0)
        	return MAX_VALUE;
        
        if(dividend == MIN_VALUE)
        {
        	if(divisor == -1)
        		return MAX_VALUE;
        	
			dividend += abs(divisor);
			res ++; 
        }
        if(divisor == MIN_VALUE)  
	    {  
	        return res;  
	    }  
        int flag = sign(dividend,divisor);
        dividend = abs(dividend);
        divisor  = abs(divisor);
        int divid = dividend >> 1;
        int divis = divisor;
		cout<<"dividend="<<divid<<endl;
		cout<<"divis="<<divis<<endl;
		while(divid >= divis)
		{
			move +=1;
			divis = divis << 1; 
			
		}
		while(move >= 0)
		{
			if(dividend >= divis)
			{
				res += 1<<move;
				dividend =  dividend - divis;
			} 
			divis = divis >> 1;
			move --;
		}

		if(flag == 1)
			return res;
		else
			return -res;
    }
    int sign(int num1, int num2)
    {
    	if((num1 > 0 && num2>0) || (num1 < 0 && num2<0))
    		return 1;
    	else
    		return -1;
    }
};

int main()
{
	Solution s;
	//int dividend = 2147483647;
	int dividend = 9;
	int divisor  = 1;
	int res = s.divide(dividend,divisor);
	cout<<res<<endl;
	//int a = dividend << 1;
	//cout<<"a="<<a<<endl;
	//cout<<"dividend="<<dividend<<endl;
}
