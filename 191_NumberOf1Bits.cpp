#include<iostream>
using namespace std;
#include<unordered_map>

int hammingWeight_mini(uint32_t n) {
	unordered_map<int, int> hash;
	hash[0] = 0;
	hash[1] = 1;
	int curr = 2;
	while(curr<=n){
		for(int pos = curr; pos<curr*2; pos++){
			hash[pos] = hash[pos-curr]+1;
		}
		curr*=2;
	}
	return hash[n];

}

int hammingWeight(uint32_t n) {
	int count = 0;
	while(n>0){
		count += n&1;
		n = n>>1;
	}
	return count;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    int input;
    cin>>input;

	cout<<hammingWeight(input);    

	return 0;
}
