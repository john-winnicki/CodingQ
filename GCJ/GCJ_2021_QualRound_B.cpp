#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
using db = double; 
using str = string; // yay python!
 
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;
 
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>; 
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>; 
using vpd = vector<pd>;
 
#define tcT template<class T
#define tcTU tcT, class U
// ^ lol this makes everything look weird but I'll try it
tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
tcT> using PR = pair<T,T>;
 
// pairs
#define mp make_pair
#define f first
#define s second
 
// vectors
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend() 
#define sor(x) sort(all(x)) 
#define rsz resize
#define ins insert 
#define ft front() 
#define bk back()
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define lb lower_bound 
#define ub upper_bound 
 
// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5;
const ll INF = 1e18; // not too close to LLONG_MAX
const ld PI = acos((ld)-1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;

string removeQuestionMarks(string s, int len){
	int j = 0;
	for(int i = 1; i<len; i++){
		if(s[j]!=s[i] || s[j]!='?'){
			j++;
			s[j] = s[i];
		}
	}
	j++;
	s.resize(j);
	return s;
}

void solve(){
	
	int X, Y;
	str S;
	cin>>X>>Y;
	cin>>S;

	char mini;
	if(X<Y) mini = 'C';
	else mini = 'J';

	int len = S.length();
	// string consider = removeQuestionMarks(S, len);
    // int curr = 0;
    // while(curr<len && S[curr]!='?') curr++;
    // int prev = curr;
    // curr++;
    // while(curr<len && S[curr]!='?') curr++;

    // int next = curr+1;
    // while(next<len && S[next]=='?'){
    // 	if(S[next]!='?') next++;
    // 	else{
    // 		if(S[prev]=='C' && S[next]=='C'){
    // 			for(int i = prev; i<next; i++) S[i] = 'C';
    // 		}
    // 		else if(S[prev]=='J' && S[next]=='J'){
    // 			for(int i = prev; i<next; i++) S[i] = 'J';
    // 		}
    // 		else if(S[prev]=='J'){
    // 			for(int i = prev; i<next; i++) S[i] = 'J';	
    // 		}
    // 		else{
    // 			for(int i = prev; i<next; i++) S[i] = 'C';
    // 		}
    // 	    prev = curr;
    // 	    curr = next;
    // 	    next = next+1;
    // 	}
    // }

	int curr = 0;
	while(curr<len && S[curr]=='?') curr++;
	int prev = curr;
	if(prev==len){
		cout<<0<<endl;
		return;
	}
	prev--;
	while(prev>=0){
		S[prev] = S[curr];
		prev--;
	}

	prev = curr;
	while(curr<len){
		if(S[curr]!='?') prev = curr;
		else{
			S[curr] = S[prev];
		}
		curr++;
	}

    // cout<<S<<endl;
    curr = 0;
    int cost = 0;
    while(curr<len-1){
    	if(S[curr]=='C' && S[curr+1]=='J') cost += X;
    	else if(S[curr]=='J' && S[curr+1]=='C') cost += Y;
    	curr++;
    }

    cout<<cost<<endl;

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("../IO/input.txt", "r", stdin);
	freopen("../IO/output.txt", "w", stdout);
	#endif

    int T;
    cin>>T;

    F0R(i, T){
    	cout<<"Case #"<<i+1<<": ";
    	solve();
    }

	return 0;
}
