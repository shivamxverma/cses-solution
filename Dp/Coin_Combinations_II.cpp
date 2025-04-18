#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair
void setIO(string name = "") { 
	ios_base::sync_with_stdio(0);
	cin.tie(0);  // see Fast Input & Output
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin);  // see Input & Output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

ll dp[1000001];

const int MOD = (int)1e9 + 7;

int main() {
	int n;
	cin >> n;
	int x = n*(n-1)/4;
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int weight = 0; weight <= x; weight++) {
			if (weight - i >= 0) { 
				dp[weight] += dp[weight - i];
				dp[weight] %= MOD;
			}
		}
	}
	cout << dp[x] << '\n';
}