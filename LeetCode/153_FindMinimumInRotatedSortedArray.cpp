#include<iostream>
using namespace std;
#include<vector>

int findMin(vector<int>& nums) {
	int l = 0;
	int r = nums.size()-1;

	while(l<=r){
		if(nums[l]<=nums[r]) return nums[l];
		int mid = l + (r-l)/2;
		if(nums[mid]>=nums[l]) l = mid+1;
		else r = mid;
	}
	return nums[l];
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    vector<int> vec;
    int input;
    while(cin>>input){
    	vec.push_back(input);
    }

    cout<<findMin(vec)<<endl;

	return 0;
}
