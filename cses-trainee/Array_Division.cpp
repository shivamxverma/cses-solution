// Jai shree Ram
// Shivam Verma

#include <bits/stdc++.h>
using namespace std;

// Common definitions
const long long INF = LLONG_MAX;
#define ll long long int
#define all(v) (v).begin(), (v).end()
#define vc vector<ll>
#define loop(i, b) for (int i = 0; i < b; i++)

// Fast input for vector
template <class T>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &vl : v) in >> vl;
    return in;
}

// Output vector
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    for (const auto &i : v) out << i << " ";
    return out;
}

bool can(vc &v, ll m, int k) {
    ll cur = 0;
    for (ll i : v) {
        if (i > m) return false;
        if (cur + i > m) {
            k--;
            cur = i;
        } else {
            cur += i;
        }
    }
    return k > 0;
}

void MahavirCoder() {
    int n, k;
    cin >> n >> k;
    vc v(n);
    cin >> v;

    ll sum = accumulate(all(v), 0LL);
    ll l = 0, r = sum;

    while (l <= r) {
        ll m = l + (r - l) / 2;
        if (can(v, m, k)) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    cout << l << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) MahavirCoder();
    return 0;
}
