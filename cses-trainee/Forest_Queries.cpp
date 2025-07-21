#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define ll long long int

int n, q;

int main() {
    cin >> n >> q;
    vector<vector<ll>> prefix(n+1, vector<ll>(n+1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char x;
            cin >> x;
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] 
                           - prefix[i-1][j-1] + (x == '*');
        }
    }

    while (q--) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;

        ll ans = prefix[y2][x2] 
               - prefix[y1-1][x2] 
               - prefix[y2][x1-1] 
               + prefix[y1-1][x1-1];
        cout << ans << "\n";
    }
}
