/*
*Max Points on a Line
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<map>
#include<stdlib.h>
using namespace std;

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int maxNum = 0;
        
        int size = points.size();
        if(size <= 2)
        	return size;
        
        for(int i=0;i<size;i++){
        	map<double, int> myMap;
        	int self = 1, vertical = 0;
        	for(int j=i+1;j<size;j++){
        		int x1=points[i].x, y1=points[i].y;
        		int x2=points[j].x, y2=points[j].y;
        		if(x1 == x2 && y1 == y2)
        			self ++;
        		else if(x1 == x2)
        			vertical ++;
        		else{
        			double a = (double)(y1-y2)/(x1-x2);
        			if(myMap.find(a) == myMap.end())
        				myMap[a] = 1;
        			else
        				myMap[a] += 1;
        		}
        	}
        	map<double,int>::iterator iter = myMap.begin(); 
        	int oneMax = vertical;
			for(;iter!=myMap.end();iter++){
        		if(oneMax < iter->second)
        			oneMax = iter->second;
        	}
        	oneMax += self;
        	if(oneMax > maxNum)
        		maxNum = oneMax;
        }
        return maxNum;
    }
};
