// using namespace std;
// using string 
#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>


void solve(long long x, long long y, long long l, long long r, long long k){ //TOO LAZY TO SWITCH THE VARIABLES TO PROPER PLACES
	//SHOULD BE TRYING TO TO USE X AND Y!
	for(int num = l; num<=r; num++){
		if(num*k>y){
			cout<<"NO";
			return;
		}
		else if(num*k>=x && num*k<=y){
			cout<<"YES";
			return;
		}
	}
	cout<<"NO";
	return;	
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("../IO/input.txt", "r", stdin);
	freopen("../IO/output.txt", "w", stdout);
	#endif

    int l,r,x,y,k;
    cin>>l>>r>>x>>y>>k;

    solve(l, r, x, y, k);

	return 0;
}
