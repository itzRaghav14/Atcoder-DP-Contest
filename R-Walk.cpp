#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define dbg(...) ; 
#define debug(...) ; 
#define crndl ; 
#endif

const int MOD = 1e9 + 7;
using matrix = vector<vector<int>>;

int add (int a, int b) {
	int res = a + b;
	if(res >= MOD) res -= MOD;
	return res;
}

int mul (int a, int b) {
	return 1LL * a * b % MOD;
}

matrix single (int n) {
	matrix res = vector<vector<int>> (n, vector<int> (n, 0));
	for(int i = 0; i < n; i++) {
		res[i][i] = 1;
	}
	return res;
}

matrix mul (matrix &a, matrix &b) {
	int n = a.size();
	matrix res(n, vector<int> (n, 0));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < n; k++) {
				res[i][k] = add(res[i][k], mul(a[i][j], b[j][k]));
			}
		}
	}
	return res;
}

matrix powermod (matrix a, long long b) {
	int n = a.size();
	matrix res = single(n);
	while(b) {
		if(b & 1) res = mul(res, a);
		b >>= 1;
		a = mul(a, a);
	}
	return res;
}

void solve() {
	
	int n;
	long long k;
	cin >> n >> k;
	
	vector<vector<int>> a(n, vector<int> (n, 0));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	
	matrix mat = powermod(a, k);
	
	dbg(mat);
	
	int ans = 0;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			ans = add (ans, mat[i][j]);
		}
	}
	
	cout << ans << endl;
	
}

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("io/input.txt", "r", stdin);
    freopen("io/output.txt", "w", stdout);
    freopen("io/error.txt", "w", stderr);
    #endif
	
	int t = 1;
	// cin >> t;
	
	for(int _t = 1; _t <= t; _t++) {
		debug(Testcase, _t);
		solve();
		crndl;
	}
	
	return 0;
}
