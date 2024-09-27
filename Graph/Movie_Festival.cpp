#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()
bool cmp(pair<ll, ll> p1, pair<ll, ll> p2)
{
    return (p1.second < p2.second);
}
int main()
{
    int n;
    cin >> n;
    vector<pair<ll, ll>> vp;
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        vp.push_back({x, y});
    }
    sort(all(vp), cmp);
    ll ans = 1;
    ll last = vp[0].second;
    for (int i = 1; i < n; i++)
    {
        if (last <= vp[i].first)
        {
            last = vp[i].second;
            ans++;
        }
    }
    cout << ans << endl;
}