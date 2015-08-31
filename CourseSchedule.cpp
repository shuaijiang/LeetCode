/*
*Course Schedule 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<map>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
	map<int, vector<int> > myMap;
	map<int, vector<int> >::iterator iter;
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        int len = prerequisites.size();
    	vector<int> visit(numCourses, 0);   

		
		for(int i=0;i<len;i++){
        	int num1 = prerequisites[i].first;
        	int num2 = prerequisites[i].second;
        	if(myMap.find(num1) == myMap.end()){
        		vector<int> vec(1,num2);
        		myMap[num1] = vec;
        	}
        	else{
        		(myMap[num1]).push_back(num2);
        	}
        }
        for(iter = myMap.begin();iter != myMap.end(); iter++){
        	vector<int> nums = iter->second;
        	int begin = iter->first;
        	visit[begin] = -1;
			for(int j=0;j<nums.size();j++){
				if(dfs(nums[j], visit))
					return false;
			}
			visit[begin] = 1;
        }
        return true;
    }
    bool dfs(int num, vector<int> &visit) {
    	cout<<"num="<<num<<endl;
    	if(visit[num] == -1)
    		return true;
    	if(visit[num] == 1)
    		return false;
    		
    	visit[num] = -1;
		vector<int> vec;
		if(myMap.find(num) != myMap.end()) 
			vec = myMap[num];
		
		for(int i=0;i<vec.size();i++){
			if(dfs(vec[i], visit))
				return true;
		}
		visit[num] = 1;
		return false;
    }
};

int main(){
	Solution s;
	pair<int, int> n1(0,1);
	pair<int, int> n2(3,1);
	pair<int, int> n3(1,3);
	pair<int, int> n4(3,2);
	
	vector<pair<int,int> > vec;
	vec.push_back(n1);
	vec.push_back(n2);
	vec.push_back(n3);
	vec.push_back(n4);
	bool res = s.canFinish(4, vec);
	cout<<"res="<<res<<endl;
	system("pause");
	return 0;
}
