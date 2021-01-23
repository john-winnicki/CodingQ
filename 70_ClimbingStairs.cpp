#include<iostream>
using namespace std;

int climbStairs(int n) {
	if(n==1) return 1;
	else if(n==2) return 2;
	else{
		int step1 = 1;
		int step2 = 2;
		for(int i = 3; i<=n; i++){
			int temp = step1;
			step1 = step2;
			step2 = temp+step2;
		}
		return step2;
	}        
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    int n;
    cin>>n;
    cout<<climbStairs(n)<<endl;
	return 0;
}
