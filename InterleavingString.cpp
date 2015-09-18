/*
*Interleaving String
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<string.h>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        int k = s3.size();
        if(k == 0)
        	return true;
        if( m+n != k)
        	return false;

		vector<vector<int> >  matrix(m+1, vector<int>(n+1, 0));	
        
		matrix[0][0] = 1;        
        for(int i=1;i<=m;i++){
        	if(s3[i-1] == s1[i-1])
				matrix[i][0] = 1;
			else
				break;
        }
        for(int j=1;j<=n;j++){
        	if(s3[j-1] == s2[j-1])
				matrix[0][j] = 1;
			else
				break;
        }
        for(int i=1;i<=m;i++){
			char c1 = s1[i-1];
			for(int j=1;j<=n;j++){
				char c2 = s2[j-1];
				char c3 = s3[i+j-1];
				if(c1 == c3){
					matrix[i][j] = matrix[i-1][j] || matrix[i][j];
				}
				if(c2 == c3)
					matrix[i][j] = matrix[i][j-1] || matrix[i][j];	
			}
        }
        for(int i=0;i<=m;i++){
        	for(int j=0;j<=n;j++)
        		cout<<matrix[i][j]<<" ";
        	cout<<endl;
        }
        	
        return matrix[m][n];
    }
};
int main(){
	Solution s;
	//string s1("aabd");
	//string s2("abdc");
	//string s3("aabdbadc");
	string s1("a");
	string s2("b");
	string s3("ab");
	bool res = s.isInterleave(s1,s2,s3);
	cout<<"res="<<res<<endl;
	system("pause");
	return 0;
}
