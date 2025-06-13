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


void MahavirCoder() {
    int n,a,b;cin>>n>>a>>b;

    vc arr(n);cin>>arr;

    int i = 0 , j = 0;
    int cur = 0;

    // while(j<n){
    //     cur += arr[i];
    //     if()
    // }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) MahavirCoder();
    return 0;
}
