/*
*Compare Version Numbers
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int count = 0;
        if(num.size() > 1)
        {
        	for(count=0;count<num.size();++count)
	        {
	        	if(count == 0)
	        	{
	        		if(num[count] > num[count+1])
	        			return count;
	        	}
	        	else if(count == num.size()-1)
	        	{
	        		if(num[count] > num[count-1])
	        			return count;
	        	}
	        	else
	        	{
	        		if(num[count] > num[count-1] && num[count] > num[count+1]) 
	        			return count;
	        	}
	        }
        }
        else
        	return count;
    }
};

int main() 
{
	Solution s;
	int array[] = {1,2,3,1};
	vector<int> num;
	for(int count=0;count<4;++count)
	{
		num.push_back(array[count]);
	}
	vector<int>::iterator iter;
	for(iter=num.begin();iter<num.end();++iter)
		cout<<*iter<<endl;
	int index = s.findPeakElement(num);
	cout<<"index="<<index<<endl;
}
