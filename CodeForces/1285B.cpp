// using namespace std;
// using string 
#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>

long long maxSubArray(vector<int> arr, int l, int r){
	long long tot = arr[l];
	long long curr = 0;
	for(int i = l; i<=r; i++){
		curr += arr[i];
		tot = max(tot, curr);
		if(curr<0){
			curr = 0;
		}
	}
	return tot;
}

void solve(int n, vector<int> &arr){
	long long max_num = max(maxSubArray(arr, 0, arr.size()-2), maxSubArray(arr, 1, arr.size()-1));
	long long sum = 0;
	for(int i : arr) sum += i;
	if(max_num>=sum){
		cout<<"NO"<<endl;
	}
	else{
		cout<<"Yes"<<endl;
	}
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("../IO/input.txt", "r", stdin);
	freopen("../IO/output.txt", "w", stdout);
	#endif

    
    int t; 
    cin>>t;

    for(int i = 0; i<t; i++){
    	int n;
    	cin>>n;
    	vector<int> curr;
    	int input;
    	for(int j = 0; j<n; j++){
    		cin>>input;
    		curr.push_back(input);
    	}
    	solve(n, curr);
    }

	return 0;
}
