/*
*Remove Element
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
		int new_len = 0;
		for(int count=0;count<n;++count)
        {
        	if(A[count] != elem)
        	{
        		A[new_len] = A[count];
        		new_len ++;	
        	}
        }
        return new_len;
    }
};
