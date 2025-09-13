// Jai shree Ram
// Shivam verma

#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// some common Defination

const long long INF = 1e18;
#define ll long long int
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define vc vector<ll>
typedef pair<int, int> pi;
const int mod = 1000000007;
const int N = 1e5;
#define endl "\n"
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sloop(i, a, b) for (int i = a; i < b; i++)
#define loop(i, b) for (int i = 0; i < b; i++)
#define rloop(i, a, b) for (int i = a; i >= b; i--)
#define print(str) cout << str << "\n"

// Inbuilt Function

#define sum(a) (accumulate((a).begin(), (a).end(), 0LL))
#define unique_el(s) \
    sort(all(s));    \
    s.erase(unique(s.begin(), s.end()), s.end())
#define minel(a) (*min_element((a).begin(), (a).end()))
#define maxel(a) (*max_element((a).begin(), (a).end()))
#define mini(a) (min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a) (max_element((a).begin(), (a).end()) - (a).begin())
#define cnt(a, x) (count((a).begin(), (a).end(), (x)))
#define lob(a, x) (lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define upb(a, x) (upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

// input array

template <class T>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &vl : v)
    {
        in >> vl;
    }
    return in;
}
template <typename T>
void pvec(vector<T> &v)
{
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

// output array

template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    for (const auto &i : v)
    {
        out << i << " ";
    }
    return out;
}

// Prefix sum

template <typename T>
void prefixSum(const vector<T> &arr, vector<T> &prefix)
{
    int n = arr.size();
    prefix.resize(n);
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }
}

int n, m, k;
vector<vector<pair<int, int>>> graph;

void MahavirCoder()
{
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> graph(n);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        graph[u].push_back({v, w});
    }

    vector<vector<ll>> dist(n, vector<ll>(k + 1, INF));
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> pq;

    dist[0][0] = 0;
    pq.push({0, 0, 0});

    while (!pq.empty())
    {
        auto [ww, u, isused] = pq.top();
        pq.pop();

        if (u == n - 1)
        {
            cout << ww << "\n";
            return;
        }

        if (dist[u][isused] < ww)
            continue;

        for (auto [v, w] : graph[u])
        {
            if (dist[v][isused] > ww + w)
            {
                dist[v][isused] = ww + w;
                pq.push({dist[v][isused], v, isused});
            }

            if (isused < k && dist[v][isused + 1] > ww + w / 2)
            {
                dist[v][isused + 1] = ww + w / 2;
                pq.push({dist[v][isused + 1], v, isused + 1});
            }
        }
    }

    ll result = INF;

    for (int i = 0; i <= k; i++)
    {
        result = min(result, dist[n - 1][i]);
    }

    cout << result << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin>>t;
    while (t--)
    {
        MahavirCoder();
    }
}