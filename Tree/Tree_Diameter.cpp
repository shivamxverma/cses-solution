#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
int diameter = 0;

int dfs(int node, int parent)
{
    int max1 = -1, max2 = -1;
    for (int child : tree[node])
    {
        if (child == parent)
            continue;
        int h = dfs(child, node);
        if (h > max1)
        {
            max2 = max1;
            max1 = h;
        }
        else if (h > max2)
        {
            max2 = h;
        }
    }
    if (max1 != -1 && max2 != -1)
    {
        diameter = max(diameter, max1 + max2 + 2);
    }
    else if (max1 != -1)
    {
        diameter = max(diameter, max1 + 1);
    }
    return max1 + 1;
}

void solve()
{
    int n;
    cin >> n;
    tree.assign(n, vector<int>());

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(0, -1);
    cout << diameter << endl;
}

int main()
{
    solve();
    return 0;
}
