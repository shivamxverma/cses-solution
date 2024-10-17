#include<bits/stdc++.h>
using namespace std;

#define ll long long int

void solve(){
    int n;
    cin >> n;
    vector<int> p1, p2;
    
    if ((n * (n + 1) / 2) % 2 != 0) {
        cout << "NO\n";
        return;
    }
    
    ll p1s = 0, p2s = 0;
    for (int i = n; i >= 1; i--) {
        if (p1s <= p2s) {
            p1.push_back(i);
            p1s += i;
        } else {
            p2.push_back(i);
            p2s += i;
        }
    }
    
    cout << "YES\n";
    cout << p1.size() << "\n";
    for (int x : p1) cout << x << " ";
    cout << "\n" << p2.size() << "\n";
    for (int x : p2) cout << x << " ";
    cout << "\n";
}

int main(){
    solve();
}