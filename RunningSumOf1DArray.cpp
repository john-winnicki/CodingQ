#include<iostream>
using namespace std;
#include <vector>
#include <string>

void runningSum(int nums[], int len) {
	for(int i = 1; i<len; i++){
		nums[i] += nums[i-1];
	}
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif


	int len;
	cin >> len;

	int nums[len];
	for(int i = 0; i<len; i++) cin >> nums[i];

	runningSum(nums, len);

	for(int i = 0; i<len; i++) cout << nums[i] << endl;

	return 0;
}
