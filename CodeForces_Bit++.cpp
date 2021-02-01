#include<iostream>
using namespace std;
#include<string>

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    int temp;
    cin>>temp;
    int curr = 0;
    for(int i = 0; i<temp; i++){
    	string s;
    	cin>>s;
    	// cout<<s<<endl;
    	if(s[0]=='X'){
    		if(s[1]=='+') curr++;
    		else curr--;
    	}
    	else{
    		if(s[0]=='+') curr++;
    		else curr--;
    	}
    }
    cout<<curr;

	return 0;
}
