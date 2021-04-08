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

bool good(vector<vi> matrix, int R, int C){
	F0R(i, R){
		F0R(j, C){
			int up = 0;
			int down = 0;
			int left = 0;
			int right = 0;
			if(i!=0) up = abs(matrix[i][j]-matrix[i-1][j]);
			if(i!=R-1) down = abs(matrix[i][j]-matrix[i+1][j]);
			if(j!=0) left = abs(matrix[i][j]-matrix[i][j-1]);
			if(j!=C-1) right = abs(matrix[i][j]-matrix[i][j+1]);

			if(left>1 || right>1 || down>1 || up>1) return false;
		}
	}
	return true;
}

ll adjustMax(vector<vi>& matrix, int R, int C, vector<vector<bool>>& seen){
	int maxi = -1;
	int maxj = -1;
	F0R(i, R){
		F0R(j, C){
			if((!seen[i][j]) && ((maxi==-1 || matrix[maxi][maxj]<matrix[i][j]))){
				maxi = i;
				maxj = j;
			}
		}
	}
	ll count = 0;
	if(maxi>0 && matrix[maxi][maxj]>matrix[maxi-1][maxj]){
		count += matrix[maxi][maxj]-matrix[maxi-1][maxj]-1;
		matrix[maxi-1][maxj] = matrix[maxi][maxj]-1;
	}
	if(maxi<R-1 && matrix[maxi][maxj]>matrix[maxi+1][maxj]){
		count += matrix[maxi][maxj]-matrix[maxi+1][maxj]-1;
		matrix[maxi+1][maxj] = matrix[maxi][maxj]-1;
	}
	if(maxj>0 && matrix[maxi][maxj]>matrix[maxi][maxj-1]){
		count += matrix[maxi][maxj]-matrix[maxi][maxj-1]-1;
		matrix[maxi][maxj-1] = matrix[maxi][maxj]-1;
	}
	if(maxj<C-1 && matrix[maxi][maxj]>matrix[maxi][maxj+1]){
		count += matrix[maxi][maxj]-matrix[maxi][maxj+1]-1;
		matrix[maxi][maxj+1] = matrix[maxi][maxj]-1;
	}

	// cout<<maxi<<" "<<maxj<<endl;

	seen[maxi][maxj] = true;

    return count;
}

// int adjustMax(vector<vi>& matrix, int R, int C){
// 	int maxi = 0;
// 	int maxj = 0;
// 	int maxDiff = 0;
// 	F0R(i, R){
// 		F0R(j, C){
// 			int currDiff = 0;
// 			if(i!=0) currDiff += abs(matrix[i][j]-matrix[i-1][j]);
// 			if(i!=R-1) currDiff += abs(matrix[i][j]-matrix[i+1][j]);
// 			if(j!=0) currDiff += abs(matrix[i][j]-matrix[i][j-1]);
// 			if(j!=C-1) currDiff += abs(matrix[i][j]-matrix[i][j+1]);
// 			if(currDiff>maxDiff){
// 				maxi = i;
// 				maxj = j;
// 				maxDiff = currDiff;
// 			}
// 		}
// 	}
// 	int count = 0;
// 	if(maxi>0 && matrix[maxi][maxj]>matrix[maxi-1][maxj]){
// 		count += matrix[maxi][maxj]-matrix[maxi-1][maxj]-1;
// 		matrix[maxi-1][maxj] = matrix[maxi][maxj]-1;
// 	}
// 	if(maxi<R-1 && matrix[maxi][maxj]>matrix[maxi+1][maxj]){
// 		count += matrix[maxi][maxj]-matrix[maxi+1][maxj]-1;
// 		matrix[maxi+1][maxj] = matrix[maxi][maxj]-1;
// 	}
// 	if(maxj>0 && matrix[maxi][maxj]>matrix[maxi][maxj-1]){
// 		count += matrix[maxi][maxj]-matrix[maxi][maxj-1]-1;
// 		matrix[maxi][maxj-1] = matrix[maxi][maxj]-1;
// 	}
// 	if(maxj<C-1 && matrix[maxi][maxj]>matrix[maxi][maxj+1]){
// 		count += matrix[maxi][maxj]-matrix[maxi][maxj+1]-1;
// 		matrix[maxi][maxj+1] = matrix[maxi][maxj]-1;
// 	}

//     return count;
// }

// int adjustMin(vector<vi>& matrix, int R, int C){
// 	int maxi = 0;
// 	int maxj = 0;
// 	int maxDiff = 0;
// 	F0R(i, R){
// 		F0R(j, C){
// 			int currDiff = 0;
// 			if(i!=0) currDiff += abs(matrix[i][j]-matrix[i-1][j]);
// 			if(i!=R-1) currDiff += abs(matrix[i][j]-matrix[i+1][j]);
// 			if(j!=0) currDiff += abs(matrix[i][j]-matrix[i][j-1]);
// 			if(j!=C-1) currDiff += abs(matrix[i][j]-matrix[i][j+1]);
// 			if(currDiff>maxDiff){
// 				maxi = i;
// 				maxj = j;
// 				maxDiff = currDiff;
// 			}
// 		}
// 	}
// 	int count = 0;
// 	if(maxi>0 && matrix[maxi][maxj]<matrix[maxi-1][maxj]){
// 		count += matrix[maxi-1][maxj]-matrix[maxi][maxj]-1;
// 		matrix[maxi][maxj] = matrix[maxi-1][maxj] - 1;
// 	}
// 	if(maxi<R-1 && matrix[maxi][maxj]<matrix[maxi+1][maxj]){
// 		count += matrix[maxi+1][maxj]-matrix[maxi][maxj]-1;
// 		matrix[maxi][maxj] = matrix[maxi+1][maxj] - 1;
// 	}
// 	if(maxj>0 && matrix[maxi][maxj]<matrix[maxi][maxj-1]){
// 		count += matrix[maxi][maxj-1]-matrix[maxi][maxj]-1;
// 		matrix[maxi][maxj] = matrix[maxi][maxj-1] - 1;
// 	}
// 	if(maxi<C-1 && matrix[maxi][maxj]<matrix[maxi][maxj+1]){
// 		count += matrix[maxi][maxj+1]-matrix[maxi][maxj]-1;
// 		matrix[maxi][maxj] = matrix[maxi][maxj+1] - 1;
// 	}

//     return count;
// }

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

	vector<vector<bool>> seen(R, vector<bool>(C, false));

	ll count = 0;
	int turn = 0;
	while(!good(matrix, R, C)){
		count += adjustMax(matrix, R, C, seen);
		// if(turn%2==0) count += adjustMax(matrix, R, C);
		// else count += adjustMin(matrix, R, C);
		// cout<<endl;
		// F0R(i, R){
		// 	F0R(j, C){
		// 		cout<<matrix[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		// cout<<endl<<endl;
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
    	cout<<"Case #"<<i+1<<": ";
    	solve();
    }

	return 0;
}
