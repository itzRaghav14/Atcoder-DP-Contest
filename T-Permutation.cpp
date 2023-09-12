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

void solve() {
	
	int n;
	cin >> n;
	
	string str;
	cin >> str;
	
	auto add = [&] (int a, int b) {
		int res = a + b;
		if(res >= MOD) res -= MOD;
		return res;
	};
	
	vector<int> dp(n + 1, 0);
	vector<int> pre(n + 1, 0);
	
	auto getSum = [&] (int l, int r) {
		if(l > r) return 0;
		if(l == 0) return pre[r];
		int res = pre[r] - pre[l - 1];
		if(res < 0) res += MOD;
		return res;
	};
	
	dp[1] = 1;
	pre[1] = 1;
	
	for(int ind = 1; ind < n; ind++) {
		vector<int> ndp (n + 1, 0);
		
		for(int last = 1; last <= ind + 1; last++) {
			
			int start = 1, end = ind;
			
			if(str[ind - 1] == '>') {
				start = last;
			} else {
				end = last - 1;
			}
      
			ndp[last] = getSum (start, end);
			
		}
		
		pre[0] = ndp[0];
		for(int j = 1; j <= ind + 1; j++) {
			pre[j] = add(pre[j - 1], ndp[j]);
		}
		
		dp = ndp;
	}
	
	int ans = getSum(1, n);
	
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
