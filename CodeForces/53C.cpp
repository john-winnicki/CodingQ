// using namespace std;
// using string 
#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>

void solve(int k){
	int l = 1;
	int r = k;
	while(l<=r){
		cout<<l<<" ";
		l++;
		if(l<=r){
			cout<<r<<" ";
			r--;
		}
	}
	return;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("../IO/input.txt", "r", stdin);
	freopen("../IO/output.txt", "w", stdout);
	#endif

    
    int k; 
    cin>>k;

    solve(k);

	return 0;
}
