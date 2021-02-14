#include<iostream>
using namespace std;
#include<string>

string LCM(string s, string t){
	int slen = s.length();
	int tlen = t.length();
	int mini = min(slen, tlen);

	string least = "-1";
	for(int i = 1; i<=mini; i++){
		int pos = 0;
		if(slen%i==0 && tlen%i==0){
			string s_test = s.substr(0, i);
			string t_test = t.substr(0, i);
			// cout << s_test << "   " << t_test << endl;
			if(s_test==t_test){
				bool bad = false;
				for(int j=0; j<slen; j+=i){
					if(s_test!=s.substr(j, i)){
						bad = true;
						break;
					}
				}
				
				if(bad) continue;

				for(int j=0; j<tlen; j+=i){
					if(t_test!=t.substr(j, i)){
						bad = true;
						break;
					}
				}
				if(bad) continue;
				else return s_test;
			}
		}
	}

	// if(least=="-1") return least;
	// else{
		// 
	// }
	return least;
}

string LCM_fin(string s, string t){
	string least = LCM(s, t);
	if(least=="-1") return "-1";
	int slen = s.length();
	int scount = slen;
	int tlen = t.length();
	int tcount = tlen;
	while(scount!=tcount){
		// cout << scount << "     " << tcount<<endl;
		if(scount<tcount) scount += slen;
		else tcount += tlen;
	}
	
	string fin = "";
	for(int i = 0; i<(scount/least.length()); i++){
		fin += least;
		// cout << fin<<endl;
	}
	return fin;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    int q;
    cin>>q;

    for(int i = 0; i<q; i++){
    	string s, t;
    	cin>>s>>t;
    	cout<<LCM_fin(s, t)<<endl;
    }

	return 0;
}
