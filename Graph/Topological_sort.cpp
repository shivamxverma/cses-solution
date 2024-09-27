#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define pb push_back

void dfs(int i,vector<int> g[], vector<bool> &vis,stack<int>  &ans)
{
    vis[i] = true;
    for (auto xd : g[i])
    {
        if (!vis[xd])
            dfs(xd,g,vis,ans);
    }
    ans.push(i + 1);
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> Graph[n];
    vector<bool> vis(n, false);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        Graph[u].pb(v);
    }
    stack<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            dfs(i,Graph,vis,ans);
    }

    while (!ans.empty())
    {
        cout << ans.top() << " ";
        ans.pop();
    }
    cout << endl;
}
int main()
{
    int t = 1;
    while (t--)
    {
        solve();
    }
}