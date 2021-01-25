#include<iostream>
using namespace std;
#include<unordered_set>
#include<vector>

int search(unordered_set<int>& hash, int i, unordered_set<int>& seen){
    int ret = 1;
    seen.insert(i);

    int left = i;
    while(hash.find(left-1)!=hash.end()){
        --left;
        seen.insert(left);
    }

    int right = i;
    while(hash.find(right+1)!=hash.end()){
        ++right;
        seen.insert(right);
    }

    return right-left+1;
}

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> hash(nums.begin(), nums.end());
    unordered_set<int> seen;

    int maxi = 0;

    for(int i: nums){
        if(seen.find(i)==seen.end()){
            maxi = max(maxi, search(hash, i, seen));
        }
    }
    return maxi;
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

    cout<<longestConsecutive(vec);

	return 0;
}
