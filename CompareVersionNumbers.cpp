/*
*Compare Version Numbers
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<sstream>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
		vector<string> vec1 = str2Vector(version1);
		vector<string> vec2 = str2Vector(version2);
		int strLarger;
		int addSize = 0;
		if(vec1.size() > vec2.size())
		{
			addSize = vec1.size() - vec2.size();
			vectorRaise(vec2,addSize); 
		}
		else if(vec1.size() < vec2.size())
		{
			addSize = vec2.size() - vec1.size();
			vectorRaise(vec1,addSize); 
		}
		vector<string>::iterator iter1,iter2;
		for(iter1=vec1.begin(),iter2=vec2.begin();iter1<vec1.end()&&iter2<vec2.end();++iter1,++iter2)
		{
			strLarger = strCompare(*iter1,*iter2);
			if(strLarger == 1)
				return 1;
			else if(strLarger == -1)
				return -1;
			else if(iter1==vec1.end()-1 && iter2==vec2.end()-1)
			{
				if(strLarger == 0)
					return 0;
			}
		} 
    }
    int strCompare(string str1, string str2)
    {
    	int num1=str2Integer(str1);
		int num2=str2Integer(str2);
		if(num1>num2)
			return 1;
		else if(num1<num2)
			return -1;
		else
			return 0;
    }
    int str2Integer(string str)
    {
    	stringstream ss;
    	int num;
    	ss.clear();
    	ss.str("");
    	ss<<str;
    	ss>>num;
    	return num;
    }
    vector<string> str2Vector(string str)
    {
		string strNum, strTemp;
		stringstream ss;
		vector<string> strVec;
		for(int count=0;count<str.size();++count)
		{
			if(count == str.size()-1)
			{
				ss.clear();
				ss<<str[count];
				ss>>strTemp;
				strNum.append(strTemp);
				strVec.push_back(strNum);
			}
			if(str[count] == '.')
			{
				strVec.push_back(strNum);
				strNum.clear();
			}
			else
			{
				ss.clear(); 
				ss<<str[count];
				ss>>strTemp;
				strNum.append(strTemp);
			}
		}
		return strVec;
    }
	void vectorRaise(vector<string> & vec,int addSize)
	{
		for(int count=0;count<addSize;count++)
			vec.push_back("0");
	}
};

int main()
{
	string str1 = "1.0";
	string str2 = "0.1";
	Solution s;
	int res = s.compareVersion(str1,str2);
	cout<<"res="<<res<<endl;
	//system("pause");
}
