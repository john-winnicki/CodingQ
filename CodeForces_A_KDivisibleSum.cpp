#include<iostream>
using namespace std;



int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    int len;
    cin>>len;
    for(int i = 0; i<len; i++){
    	int n, k;
    	cin>>n>>k;
    	int curr = k;
    	while(curr<n) curr += k;
    	k = curr;
    	cout<<k/n+(k%n==0 ? 0 : 1)<<endl;
    }

	return 0;
}
