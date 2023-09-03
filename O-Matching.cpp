#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define dbg(...) ; 
#define debug(...) ; 
#define crndl ; 
#endif

const int N = 21;
const int MX = 1 << N;
const int MOD = 1e9 + 7;

int n, mx;
int a[N][N];
int dp[N][MX];

void modadd (int &a, int b) {
	a += b;
	if(a >= MOD) a -= MOD;
}

int f(int first, int mask) {
	
	if(first == n) {
		return 1;
	}
	
	if(dp[first][mask] != -1) {
		return dp[first][mask];
	}
	
	// int res = 0;
	
	int &res = dp[first][mask];
	res = 0;
	
	for(int second = 0; second < n; second++) {
		if(a[first][second] == 0) continue;
		int bit = 1 << second;
		if(mask & bit) continue;
		modadd(res, f(first + 1, mask | bit));
	}
	
	return res;
	
}

void solve() {
	
	cin >> n;
	mx = 1 << n;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	
	memset(dp, -1, sizeof dp);
	
	f(0, 0);
	
	cout << dp[0][0] << endl;
	
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
