/*
*Number of 1 Bits
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int bitNum = 0;
        
        while(n > 1)
        {
        	if(n % 2 == 1)
        		bitNum ++;
        	
			n = n/2;
        }
        if(n%2 == 1)
        	bitNum ++;
        return bitNum;
    }
};
