#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define dbg(...) ; 
#define debug(...) ; 
#define crndl ; 
#endif

const int N = 301;
double dp[N][N][N];

void solve() {
	
	int n;
	cin >> n;
	
	vector<int> a(n);
	vector<int> cnt(4, 0);
	
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	
	auto prob = [&] (int c) {
		return 1.0 * c / n;
	};
	
	for(int three = 0; three <= n; three++) {
		for(int two = 0; two <= n; two++) {
			for(int one = 0; one <= n; one++) {
				int zero = n - one - two - three;
				if(zero == n || one + two + three > n) {
					continue;
				}
				
				double res = 1;
				res += three >= 1 ? (1.0 * three / n) * dp[three - 1][two + 1][one] : 0;
				res += two >= 1 ? (1.0 * two / n) * dp[three][two - 1][one + 1] : 0;
				res += one >= 1 ? (1.0 * one / n) * dp[three][two][one - 1] : 0;
				
				res /= (1 - 1.0 * zero / n);
				dp[three][two][one] = res;
			}
		}
	}
	
	cout << fixed << setprecision(10);
	
	cout << dp[cnt[3]][cnt[2]][cnt[1]] << endl;
	
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
