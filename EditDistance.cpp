/*
*Edit Distance
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();
        if(size1 <= 0 && size2 > 0)
        	return size2;
        else if(size2 <= 0 && size1>0)
        	return size1;
        else if(size1 <= 0 && size2 <= 0)
        	return 0;
        vector<vector<int> > distance(size1+1, vector<int>(size2+1,0));
        
        for(int i=0;i<=size1;i++)
				distance[i][0] = i;
        for(int j=0;j<=size2;j++)
        		distance[0][j] = j;
        
        for(int i=1;i<=size1;i++){
        	for(int j=1;j<=size2;j++){
        		if(word1[i-1] != word2[j-1])
        			distance[i][j] = min(min(distance[i-1][j-1], distance[i-1][j]), distance[i][j-1]) + 1;
        		else
        			distance[i][j] = distance[i-1][j-1];
        	}
        }
        return distance[size1][size2];
    }
};

int main(){
	Solution s;
	string word1 = "a";
	string word2 = "b";
	int result = s.minDistance(word1,word2);
	cout<<"result="<<result<<endl;
	system("pause");
	return 0;
}
