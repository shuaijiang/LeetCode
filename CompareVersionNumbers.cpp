/*
*Compare Version Numbers
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
		string v1_norm = removeBeginZeros(version1);
		string v2_norm = removeBeginZeros(version2);
		int num1_integer = str2IntegerPart(v1_norm);
		int num1_decimal = str2DecimalPart(v1_norm);
		int num2_integer = str2IntegerPart(v2_norm);
		int num2_decimal = str2DecimalPart(v2_norm);
		cout<<"num1="<<num1_integer<<"."<<num1_decimal<<endl;
		cout<<"num2="<<num2_integer<<"."<<num2_decimal<<endl;
    	if(num1_integer>num2_integer)
			return 1;
		else if(num1_integer<num2_integer)
			return -1;
		else
		{
			if(num1_decimal > num2_decimal)
				return 1;
			else if(num1_decimal < num2_decimal)
				return -1;
			else
				return 0;
		}
    }
    int str2IntegerPart(string str)
    {
		int integer_or_decimal = 1;
		int integer_count = 0;
		int num = 0;
		for(int count=0;count<str.size();++count)
		{
			
			if(str[count] == '.')
			{
				break;
			}
			else
			{
				if(integer_or_decimal == 1)
				{
					integer_count ++;
					num = num * pow(10.0,integer_count-1)+ (str[count]-'0');
				}
			}
		}
		return num;
    }
	int str2DecimalPart(string str)
    {
		int isDecimal = 0;
		int decimal_count = 0;
		int num = 0;
		for(int count=0;count<str.size();++count)
		{
			
			if(str[count] == '.')
				isDecimal = 1;
			else
			{
				if(isDecimal == 1)
				{
					decimal_count ++;
					num = num * pow(10.0,decimal_count-1) + (str[count]-'0');
				}
			}
		}
		return num;
    }
	string removeBeginZeros(string str)
	{
		int begin_zero = 1;
		string str_norm;
		for(int count=0;count<str.size();++count)
		{
			if(str[count] != '0')
				begin_zero = 0;
			if(begin_zero == 0)
				str_norm.push_back(str[count]);
		}
		return str_norm;
	}
};

int main()
{
	string str1 = "1.1";
	string str2 = "1.10";
	Solution s;
	int res = s.compareVersion(str1,str2);
	cout<<res<<endl;
	system("pause");
}
