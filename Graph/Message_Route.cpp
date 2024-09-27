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

int n = 100001, m = 100001;
vector<vector<int>> g(n);
vector<int> parent(n, -1);
vector<int> dist(n, INT_MAX);

void bfs(int start)
{
    dist[start] = 0;
    queue<int> q;
    q.push(start);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto xd : g[node])
        {
            int cal = dist[node] + 1;
            if (dist[xd] > cal)
            {
                dist[xd] = cal;
                parent[xd] = node;
                q.push(xd);
            }
        }
    }
}
void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[v].pb(u);
        g[u].pb(v);
    }
    bfs(0);
    if (dist[n - 1] != INT_MAX)
    {
        vector<int> res;
        int start = 0, end = n - 1;
        res.push_back(end);
        while (parent[end] != -1)
        {
            res.push_back(parent[end]);
            end = parent[end];
        }
        cout << res.size() << endl;
        reverse(all(res));
        for (auto x : res)
        {
            cout << x + 1 << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "IMPOSSIBLE\n";
    }
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