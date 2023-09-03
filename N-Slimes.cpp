#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define dbg(...) ; 
#define debug(...) ; 
#define crndl ; 
#endif

const int N = 401;

int a[N];
long long pre[N];
long long dp[N][N];

void solve() {
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	for(int i = 0; i < n; i++) {
		if(i > 0) pre[i] = pre[i - 1];
		pre[i] += a[i];
	}
	
	auto getPreSum = [&] (int l, int r) {
		if(l == 0) return pre[r];
		return pre[r] - pre[l - 1];
	};
	
	// base case
	// dp[i][j] = 0; for all i >= j
	
	for(int left = n - 1; left >= 0; left--) {
		for(int right = left + 1; right < n; right++) {
			
			long long res = 1e18;
			for(int mid = left; mid < right; mid++) {
				long long curr = dp[left][mid] + dp[mid + 1][right]
					+ getPreSum(left, right);
				res = min(res, curr);
			}
			
			dp[left][right] = res;
			
		}
	}
	
	// answer is dp[0][n - 1]
	cout << dp[0][n - 1] << endl;
	
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
