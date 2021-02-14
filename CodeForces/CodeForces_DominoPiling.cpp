#include<iostream>
using namespace std;



int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	// int temp;
	// cin>>temp;
	// for(int i = 0; i<temp; i++){
		int m, n;
    	cin>>m>>n;
    	cout<<(m*n%2==0 ? m*n/2 : (m*n-1)/2)<<endl;

	return 0;
}
