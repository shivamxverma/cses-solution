#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

#define int long long
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define vi vector<int>
typedef pair<int, int> pi;
#define setbits(x) __builtin_popcountll(x)
#define binary_rep(x) bitset<sizeof(10) * 8> binary_rep(x)
const int M = 1000000007;
#define endl "\n"
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
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (int i = a; i < b; i++)
#define Rep(i, b) for (int i = 0; i < b; i++)
#define repr(i, a, b) for (int i = a; i >= b; i--)
#define printyes cout << "YES" << "\n"
#define printno cout << "NO" << "\n"
long long inf = LLONG_MAX;
int n = 100001, m = 200001;
vector<unordered_map<int, int>> graph(n);

vector<int> dist(n, inf);

void dijktra(int s)
{
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, s});
    while (!q.empty())
    {
        auto node = q.top();
        q.pop();
        int nodex = node.second;
        int wt = node.first;
        if (wt != dist[nodex])
            continue;
        for (auto i : graph[nodex])
        {
            int ff = i.first;
            int ss = i.second;
            if (dist[ff] > (ss + dist[nodex]))
            {
                dist[ff] = ss + dist[nodex];
                q.push({dist[ff], ff});
            }
        }
    }
}
void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;  

        if (graph[u].count(v)) {
            graph[u][v] = min(graph[u][v], w);
        } else {
            graph[u][v] = w; 
        }
    }

    dijktra(0);
    for (int d = 0; d < n; d++)
    {
        cout << dist[d] << " ";
    }
    cout << endl;
}
signed main()
{
    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
}