#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, INF));

    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dp[u][v] = min(dp[u][v], 1LL * w);
        dp[v][u] = min(dp[v][u], 1LL * w);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dp[i][k] < INF && dp[k][j] < INF) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
    }

    while (q--) {
        int u, v;
        cin >> u >> v;
        if (dp[u][v] == INF)
            cout << -1 << endl;
        else
            cout << dp[u][v] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
