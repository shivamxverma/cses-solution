#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

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

int n = 1001, m = 1001;
vector<vector<char>> graph(n, vector<char>(m));
vector<vector<char>> path(n, vector<char>(m, '.'));
vector<vector<bool>> vis(n, vector<bool>(m, false));
vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<char> dirLabels = {'U', 'D', 'L', 'R'};
bool isValid(int x, int y, int t, int r)
{
    return (x >= 0 && x < t && y >= 0 && y < r);
}

bool found = false;
int sx, sy;
void dfs(int s, int e, int t, int r)
{
    vis[s][e] = true;
    if (s == 0 || e == 0 || s == t - 1 || e == r - 1)
    {
        sx = s, sy = e;
        found = true;
        return;
    }
    for (int d = 0; d < 4; d++)
    {
        int newx = s + directions[d].first;
        int newy = e + directions[d].second;
        if (graph[newx][newy] == 'M' || graph[newx][newy] == '#' || vis[newx][newy])
            continue;
        if (!isValid(newx, newy, t, r))
            continue;
        path[newx][newy] = dirLabels[d];
        dfs(newx, newy, t, r);
        if (found)
            return;
    }
}
int main()
{
    cin >> n >> m;
    int s, e;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 'A')
                s = i, e = j;
        }
    }
    if (s != -1 && e != -1)
    {
        dfs(s, e, n, m);
    }
    if (found)
    {
        cout << "YES\n";
        vector<char> ans;
        pair<int, int> curr = {sx, sy};
        while (graph[curr.first][curr.second] != 'A')
        {
            ans.push_back(path[curr.first][curr.second]);
            if (path[curr.first][curr.second] == 'U')
                curr.first++;
            else if (path[curr.first][curr.second] == 'D')
                curr.first--;
            else if (path[curr.first][curr.second] == 'L')
                curr.second++;
            else if (path[curr.first][curr.second] == 'R')
                curr.second--;
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for(auto i : ans){
            cout << i;
        }
        cout << endl;
    }
    else cout << "NO\n";
}