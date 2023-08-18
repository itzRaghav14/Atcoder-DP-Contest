#include <bits/stdc++.h>
// #include "algo/debug.h"
using namespace std;

using ll = long long;

#define endl "\n"
#define ckmin(a, b) (a > b ? a = b : a)
#define ckmax(a, b) (a < b ? a = b : a)

void solve() {
	
	int n, wt;
	cin >> n >> wt;
	
	int totVal = 0;
	const int NP = 1e9 + 10;
	
	vector<vector<int>> a(n, vector<int> (2));
	for(int i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1];
		totVal += a[i][1];
	}
	
	vector<vector<int>> dp(n + 1, vector<int> (totVal + 1, NP));
	
	dp[0][0] = 0;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= totVal; j++) {
			
			if(dp[i][j] > wt) continue;
			
			{
				ckmin(dp[i + 1][j], dp[i][j]);
			}
			
			{
				ckmin(dp[i + 1][j + a[i][1]], dp[i][j] + a[i][0]);
			}
		}
	}
	
	int ans = 0;
	
	for(int i = totVal; i > 0; i--) {
		if(dp[n][i] <= wt) {
			ans = i;
			break;
		}
	}
	
	cout << ans << endl;
	
}

int main() {
	
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("io/input.txt", "r", stdin);
    freopen("io/output.txt", "w", stdout);
    freopen("io/error.txt", "w", stderr);
    #endif
	
	int t = 1; 
	// cin >> t;
	
	while(t--) {
		solve();
	}
	
	return 0;
	
}
