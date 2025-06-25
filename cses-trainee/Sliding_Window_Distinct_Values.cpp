// Jai shree Ram
// Shivam Verma

#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
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
    int n,k;cin>>n>>k;

    vc v(n);cin>>v;
    unordered_map<ll,ll> track;

    loop(i,k){
        track[v[i]]++;
    }

    vc ans;
    ans.push_back(track.size());

    for(int i=k ; i<n ; i++){
        track[v[i]]++;
        track[v[i-k]]--;
        if(track[v[i-k]]==0){
            track.erase(v[i-k]);
        }
        ans.push_back(track.size());
    }

    for(auto i : ans)cout << i << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) MahavirCoder();
    return 0;
}
