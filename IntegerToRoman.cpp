/*
*Integer to Roman
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        int radix[] = {1000,900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string roman;
        for(int i=0;num>0;i++){
        	int count = num / radix[i];
        	num =  num % radix[i];
        	while(count>0){
        		roman += symbol[i];
        		count--;
        	}
        }
        return roman;
    }
};
