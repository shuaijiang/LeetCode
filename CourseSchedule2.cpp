/*
*Course Schedule II 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<queue>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
	queue<int> q;  //save the course whos prerequisites are all finished
	vector<int> res;
	vector<int> empty;
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(numCourses <= 0 ){ //|| !canFinish(numCourses, prerequisites
        	return res;
        }
        int len = prerequisites.size();
        if(len == 0){
        	for(int i=0;i<numCourses;i++)
        		res.push_back(i);
        	return res;
        }
        vector<int> preNum(numCourses, 0);
        for(int i=0;i<len;i++){
        	preNum[prerequisites[i].first] ++;
        }
        for(int i=0;i<numCourses;i++){
        	if(preNum[i] == 0)
        		q.push(i);
        }
        while(!q.empty()){
        	int oneCourse = q.front();
        	res.push_back(oneCourse);
        	q.pop();
        	for(int i=0;i<len;i++){
        		int course = prerequisites[i].first;
        		if(preNum[course] == 0)
        			continue;
        		if(prerequisites[i].second == oneCourse){
        			preNum[course] --;
        			if(preNum[course] == 0){
        				q.push(course);
        			}
        		}
        	}
        }
        if(res.size() != numCourses)
        	return empty;
        return res;
    }

};

int main(){
	Solution s;
	pair<int, int> n1(0,1);
	//pair<int, int> n2(2,0);
	//pair<int, int> n3(3,1);
	//pair<int, int> n4(3,2);
	
	vector<pair<int,int> > vec;
	vec.push_back(n1);
	//vec.push_back(n2);
	//vec.push_back(n3);
	//vec.push_back(n4);
	vector<int> res = s.findOrder(2, vec);
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<endl;
	system("pause");
	return 0;
}
