#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    void largestNumber(vector<int> &num) {
        vector<int>::iterator iter,iterI,iterJ;
		int temp;
		for(iterI=num.begin();iterI<num.end()-1;iterI++)
		{
			for(iterJ=iterI+1;iterJ<num.end();iterJ++)
			{
				if(largerNumber(*iterJ,*iterI))
				{
					temp = *iterJ;
					*iterJ = *iterI;
					*iterI = temp;
				}
			}
		}
		for(iter=num.begin();iter<num.end();++iter)
			cout<<*iter<<endl;
		
    }
    vector<int> number2vector(int num){
		vector<int> vec;
		int remainder;
        while(num>0){
			remainder = num%10;
			num = num/10;
			vec.push_back(remainder);
        }
		reverse(vec.begin(),vec.end());
		return vec;
    }
	void vectorRaise(vector<int> & vec,int addSize)
	{
		vector<int>::iterator iter;
		iter = vec.end()-1;
		for(int count=0;count<addSize;count++)
			vec.push_back(*iter);
	}
    bool largerNumber(int a, int b){
		vector<int> vecA = number2vector(a);
		vector<int> vecB = number2vector(b);

		vector<int>::iterator iterA;
		vector<int>::iterator iterB;
		if(vecA.size() > vecB.size())
		{
			int num = vecA.size()-vecB.size();
			vectorRaise(vecB,num);
		}
		else{
			int num = vecB.size()-vecA.size();
			vectorRaise(vecA,num);
		}
		for(iterA=vecA.begin(),iterB=vecB.begin();iterA<vecA.end()&&iterB<vecB.end();++iterA,++iterB)
		{
			if(*iterA > *iterB)
				return true;
			else if(*iterA < *iterB)
				return false;
		}
		return true;
    }
};

int main()
{
	int a[] = {3, 30, 34, 5, 9};
	int arrayNum = 5;
    Solution s;
	vector<int> vec;

	int numA = 224;
	int numB = 2243;
	for(int count=0;count<arrayNum;count++)
		vec.push_back(a[count]);
	
	
	//vector<int>::iterator iter;
	s.largestNumber(vec);
	bool larger = s.largerNumber(numA, numB);
	cout<<"larger="<<larger<<endl;
	system("pause");
	return 0;
	
}
