#include<iostream>
using namespace std;
#include<vector>

int maxSubArray(vector<int>& nums) {
	int maxmax = nums[0];
	int maxi = 0;
	for(int i : nums){
		maxi += i;
		maxmax = max(maxmax, maxi);
		if(maxi<0) maxi = 0;
	}
	return maxmax;
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

	cout<<maxSubArray(vec)<<endl;    

	return 0;
}
