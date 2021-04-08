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

void solve(){
	int R, C;
	cin>>R>>C;
	vector<vi> matrix;
	int input;

	F0R(i, R){
		vi row;
		F0R(j, C){
			cin>>input;
			row.pb(input);
		}
		matrix.pb(row);
	}

	vector<vi> leftCount(R, vi(C, 0));
	vector<vi> rightCount(R, vi(C, 0));
	vector<vi> upCount(R, vi(C, 0));
	vector<vi> downCount(R, vi(C, 0));

	F0R(i, R){
		F0R(j, C){
			if(matrix[i][j]==0) continue;
			else{
				// cout<<i<<" "<<j<<endl;
				int y = i;
				int x = j;				
				while(y>=0 && matrix[y][x]!=0){
					upCount[i][j]++;
					y--;
				}

				y = i;
				x = j;
				while(y<R && matrix[y][x]!=0){
					downCount[i][j]++;
					y++;
				}

				y = i;
				x = j;
				while(x>=0 && matrix[y][x]!=0){
					leftCount[i][j]++;
					x--;
				}

				y = i;
				x = j;
				while(x<C && matrix[y][x]!=0){
					rightCount[i][j]++;
					x++;
				}
			}
		}
	}
	// cout<<endl<<endl;
	// F0R(i, R){
	// 	F0R(j, C){
	// 		cout<<leftCount[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	int count = 0;
	F0R(i, R){
		F0R(j, C){
			int maxi = max(rightCount[i][j], downCount[i][j]);
			int mini = min(rightCount[i][j], downCount[i][j]);
			if(mini>=2 && maxi>=4){
				// cout<<"("<<i<<","<<j<<")"<<" "<<min(maxi/2, mini)-1<<endl;
				count += min(maxi/2, mini)-1;
			}
			if(mini>=4 && maxi>=2){
				// cout<<"("<<i<<","<<j<<")"<<" "<<min(mini/2, maxi)-1<<endl;
				count += min(mini/2, maxi)-1;
			}

			maxi = max(downCount[i][j], leftCount[i][j]);
			mini = min(downCount[i][j], leftCount[i][j]);
			if(mini>=2 && maxi>=4){
				// cout<<"("<<i<<","<<j<<")"<<" "<<min(maxi/2, mini)-1<<endl;
				count += min(maxi/2, mini)-1;
			}
			if(mini>=4 && maxi>=2){
				// cout<<"("<<i<<","<<j<<")"<<" "<<min(mini/2, maxi)-1<<endl;
				count += min(mini/2, maxi)-1;
			}

			maxi = max(leftCount[i][j], upCount[i][j]);
			mini = min(leftCount[i][j], upCount[i][j]);
			if(mini>=2 && maxi>=4){
				// cout<<"("<<i<<","<<j<<")"<<" "<<min(maxi/2, mini)-1<<endl;
				count += min(maxi/2, mini)-1;
			}
			if(mini>=4 && maxi>=2){
				// cout<<"("<<i<<","<<j<<")"<<" "<<min(mini/2, maxi)-1<<endl;
				count += min(mini/2, maxi)-1;
			}

			maxi = max(upCount[i][j], rightCount[i][j]);
			mini = min(upCount[i][j], rightCount[i][j]);
			if(mini>=2 && maxi>=4){
				// cout<<"("<<i<<","<<j<<")"<<" "<<min(maxi/2, mini)-1<<endl;
				count += min(maxi/2, mini)-1;
			}
			if(mini>=4 && maxi>=2){
				// cout<<"("<<i<<","<<j<<")"<<" "<<min(mini/2, maxi)-1<<endl;
				count += min(mini/2, maxi)-1;
			}

		}
	}
	cout<<count<<endl;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("../IO/input.txt", "r", stdin);
	freopen("../IO/output.txt", "w", stdout);
	#endif

    int T;
    cin>>T;
    F0R(i, T){
    	cout<<"Case #:"<<i+1<<": ";
    	solve();
    }

	return 0;
}
