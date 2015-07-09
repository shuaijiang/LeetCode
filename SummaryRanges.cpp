/*Summary Ranges
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<sstream>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        string str,tempStr;
        stringstream ss;
        int size = nums.size();
        if(nums.size()<=0)
        	return result;

    	ss<<nums[0];
    	ss>>str;
    	ss.clear();
        if(size == 1){
        	result.push_back(str);
        	return result;
        }
        if(nums[1]-nums[0] != 1){
        	result.push_back(str);
        	str="";
        }
        for(int i=1;i<nums.size()-1;i++){
        	if(nums[i] - nums[i-1] != 1 && nums[i+1]-nums[i] != 1){
				ss<<nums[i];
				ss>>str;
				ss.clear();
				result.push_back(str);
				str = "";
			}
        	else if(nums[i] - nums[i-1] == 1 && nums[i+1]-nums[i] != 1){
        		str.push_back('-');
        		str.push_back('>');
				ss<<nums[i];
				ss>>tempStr;
				ss.clear();
				str += tempStr;
        		result.push_back(str);
        		str = "";
        	}
        	else if(nums[i] - nums[i-1] != 1){
        		str = "";
				ss<<nums[i];
				ss>>str;
				ss.clear();
        	}
        }
        if(nums[size-1] - nums[size-2] == 1){
    	    str.push_back('-');
    		str.push_back('>');
			ss<<nums[size-1];
			ss>>tempStr;
			ss.clear();
			cout<<"tempStr="<<tempStr<<endl;
			str += tempStr;
    		result.push_back(str);
        }
        else{
        	str = "";
			ss<<nums[size-1];
			ss>>str;
			ss.clear();
        	result.push_back(str);
        }
        return result;
    }
};

//the code below is used for test
int main(){
	Solution s;
	vector<int> nums;
	vector<string> result;
	
	nums.push_back(0);
	nums.push_back(1);
	result=s.summaryRanges(nums);
	for(int i=0;i<result.size();i++){
		string str = result[i];
		cout<<str<<endl;
	}
	system("pause");
	return 0;
}
