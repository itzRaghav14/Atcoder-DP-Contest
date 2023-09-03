#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define dbg(...) ; 
#define debug(...) ; 
#define crndl ; 
#endif

const int N = 101;
const int K = 1e5 + 5;

int a[N];
int dp[K];

void solve() {
	
	int n, k;
	cin >> n >> k;
	
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	dp[0] = 1;
	
	for(int i = 1; i <= k; i++) {
		int res = 1;
		for(int j = 0; j < n; j++) {
			int ni = i - a[j];
			if(ni < 0) continue;
			if(dp[ni] == 1) {
				res = 0;
				break;
			}
		}
		dp[i] = res;
	}
	
	cout << (dp[k] ? "Second" : "First") << endl;
	
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
