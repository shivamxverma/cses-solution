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
    map<ll,ll> track;

    ll mxcount = 0;

    loop(i,k){
        track[v[i]]++;
        mxcount = max(mxcount,track[v[i]]);
    }

    // cout << mxcount << endl;

    vc ans;
    ll prevans = INT_MAX;
    for (auto [x,y] : track) {
        if(mxcount == y)prevans = min(prevans,x);
    }

    // cout << prevans << endl;
    ans.push_back(prevans);

    for(int i=k ; i<n ; i++){
        track[v[i]]++;
        track[v[i-k]]--;
        if(track[v[i-k]]==0){
            track.erase(v[i-k]);
        }

        if(track[v[i]] > mxcount){
            ans.push_back(v[i]);
            mxcount = track[v[i]];
        } else if(track[v[i]] == mxcount){
            if(track[prevans] < mxcount){
                ans.push_back(v[i]);
                prevans = v[i];
            } else {
                ans.push_back(prevans);
            }
        } else {
            if(v[i-k] == prevans){
                mxcount--;
                if(track[v[i]] == mxcount){
                    if(v[i] < v[i-k]){
                        prevans = v[i];
                        ans.push_back(v[i]);
                    } else {
                        
                    }
                }
            }
        }
        
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
