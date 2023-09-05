#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define dbg(...) ; 
#define debug(...) ; 
#define crndl ; 
#endif

const int N = 1e4 + 5;
const int D = 101;
const int MOD = 1e9 + 7;

int n, d;
string low, high;
int dp[N][D][2][2];

void makeSizeEqual () {
	
	int n1 = low.length();
	int n2 = high.length();
	n = n2;
	
	if(n1 < n2) {
		low = string(n2 - n1, '0') + low;
	}
}

int f (int ind, int sum, int lowTight, int highTight) {
	
	if(ind == n) {
		return sum == 0;
	}
	
	if(dp[ind][sum][lowTight][highTight] != -1) {
		return dp[ind][sum][lowTight][highTight];
	}
	
	int res = 0;
	int start = lowTight ? low[ind] - '0' : 0;
	int end = highTight ? high[ind] - '0' : 9;
	
	for (int i = start; i <= end; i++) {
		
		int newLowTight = lowTight && low[ind] - '0' == i;
		int newHighTight = highTight && high[ind] - '0' == i;
		int newSum = (sum + i) % d;
		res += f(ind + 1, newSum, newLowTight, newHighTight);
		res %= MOD;
		
	}
	
	dp[ind][sum][lowTight][highTight] = res;
	return res;
	
}

void solve() {
	
	low = "1";
	cin >> high;
	cin >> d;
	
	makeSizeEqual();
	
	memset(dp, -1, sizeof dp);
	
	int res = f(0, 0, 1, 1);
	cout << res << endl;
	
	
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
