// using namespace std;
// using string 
#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>


void solve(int n, vector<int> arr){
	sort(arr.begin(), arr.end());
	int count = 1;
	for(int i = 0; i<n; i++){
		if(arr[i]>=count){
			count++;
		}
	}
	cout<<count;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("../IO/input.txt", "r", stdin);
	freopen("../IO/output.txt", "w", stdout);
	#endif

    int n;
    cin>>n;

    int input;
    vector<int> arr;
    while(cin>>input){
    	arr.push_back(input);
    }

    solve(n, arr);

	return 0;
}
