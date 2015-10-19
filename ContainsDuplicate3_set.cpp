/*
*Contains Duplicate III
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int size = nums.size();
        if(size<=1 || k<=0)
        	return false;
        set<long> mySet; // windows which has k elements at most
        int low = 0;
        for(int i=0;i<size;++i){
        	if(mySet.size() > k){
				mySet.erase(nums[low++]);
			}
        	auto target = mySet.lower_bound((long)nums[i] - (long)t); // the first element which target >= nums[i]-t
        	if(target != mySet.end() && *target <= (long)nums[i]+(long)t) //  nums[i] + t <= target <= nums[i] + t
        		return true;
        	mySet.insert(nums[i]);
        }
		return false;
    }
};
int main(){
	Solution s;
	vector<int> nums(3,0);
	nums[0]=1;nums[1]=3;nums[2]=1;
	int k = 1; int t =1;
	bool res = s.containsNearbyAlmostDuplicate(nums, k, t);
	cout<<res<<endl;
	return 0;
}
