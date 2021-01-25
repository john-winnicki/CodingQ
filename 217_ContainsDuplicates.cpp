#include<iostream>
using namespace std;
#include<vector>
#include<unordered_set>

bool containsDuplicate(vector<int>& nums) {
	// if(nums.size()==0) return true;
	// unordered_set<int> fin;
	// for(int i : nums){
	// 	if(fin.find(i)!=fin.end()) return false;
	// 	else fin.insert(i);
	// }
	// return true;
	return ((unordered_set<int>(nums.begin(), nums.end())).size()!=nums.size());
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    vector<int> vec;
    int input;
    while(cin>>input) vec.push_back(input);

    cout<<boolalpha<<containsDuplicate(vec)<<endl;

	return 0;
}
