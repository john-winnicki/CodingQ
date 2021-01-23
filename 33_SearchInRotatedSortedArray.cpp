#include<iostream>
using namespace std;
// #include<vector>
// #include<algorithm>
#include <bits/stdc++.h>

int search(vector<int>& nums, int target) {
	if(nums.size()==0) return -1;
    if (nums.size()==1) return nums[0]==target ? 0 : -1;
	int l = 0;
	int r = nums.size()-1;
	while(l<=r){
		// cout << endl << l << "    " << r << endl;
		int mid = l + (r-l)/2;
		if(nums[mid]==target) return mid;
		if(nums[mid]>=nums[l]){
			if(target <= nums[mid] && target >= nums[l]){
				// cout << "here";
				int res = distance(nums.begin(), lower_bound(nums.begin()+l, nums.begin()+mid, target));
				if(nums[res]!=target) return -1;
				else return res;
			}
			else{
				l = mid+1;
			}
		}
		else{
			if(target >= nums[mid] && target<= nums.back()){
				int res = distance(nums.begin(), lower_bound(nums.begin()+mid, nums.end(), target));
				if(nums[res]!=target) return -1;
				else return res;
			}
			else{
				r = mid-1;
			}
		}
	}
	return -1;
}

void run(){
	int target;
	int len;
	cin >> target >> len;

	vector<int> vec;
	int input;
	for(int i = 0; i<len; i++){
		cin>>input;
		vec.push_back(input);
	}

	cout << search(vec, target) << endl;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    int tests;
    cin >> tests;

    for(int i = 0; i<tests; i++){
    	run();
    }

	return 0;
}
