#include <bits/stdc++.h>
// #include "algo/debug.h"
using namespace std;

using ll = long long;

#define endl "\n"
template <class T> bool ckmin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template <class T> bool ckmax(T &a, T b) { return a < b ? a = b, 1 : 0; }

void solve() {
	
	string s, t;
	cin >> s >> t;
	
	int n = s.length();
	int m = t.length();
	
	vector<vector<int>> dp(n + 1, vector<int> (m + 1));
	vector<vector<int>> from(n + 1, vector<int> (m + 1));
	
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= m; j++) {
			
			if(i < n && j < m && s[i] == t[j]) {
				ckmax(dp[i + 1][j + 1], dp[i][j] + 1) && (from[i + 1][j + 1] = 1);
			}
			
			if(i + 1 <= n) {
				ckmax(dp[i + 1][j], dp[i][j]) && (from[i + 1][j] = 2);
			}
			
			if(j + 1 <= m) {
				ckmax(dp[i][j + 1], dp[i][j]) && (from[i][j + 1] = 3);
			}
		}
	}
	
	string ans = "";
	int i = n, j = m;
	
	while(i > 0 && j > 0) {
		
		if(from[i][j] == 1) {
			i--, j--;
			ans += s[i];
		} else if(from[i][j] == 2) {
			i--;
		} else {
			j--;
		}
	}
	
	reverse(ans.begin(), ans.end());
	
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
