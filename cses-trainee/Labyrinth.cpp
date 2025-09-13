// Jai shree Ram
// Shivam verma

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <set>
#include <map>
using namespace std;

// some common Defination

const long long INF = LLONG_MAX;
#define ll long long int
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define vc vector<ll>
typedef pair<int, int> pi;
const int mod = 1000000007;
const int N = 1e3 + 5;
#define endl "\n"
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define loop(i, a, b) for (int i = a; i < b; i++)
#define Loop(i, b) for (int i = 0; i < b; i++)
#define Rloop(i, a, b) for (int i = a; i >= b; i--)
#define print(str) cout << str << "\n"

void MahavirCoder()
{
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, char>> dir = {{1, 0, 'D'}, {0, 1, 'R'}, {-1, 0, 'U'}, {0, -1, 'L'}};
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<char>> parent(n, vector<char>(m, '#'));
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];

    int si, sj, ei, ej;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A')
                si = i, sj = j;
            if (grid[i][j] == 'B')
                ei = i, ej = j;
        }
    }

    queue<pair<int,int>> pq;

    pq.push({si, sj});
    vis[si][sj] = true;

    while (!pq.empty())
    {
        auto [x, y] = pq.front();
        pq.pop();

        if (x == ei && y == ej)
        {
            string path = "";
            while(!(x == si && y == sj)){
                char move = parent[x][y];
                path.push_back(move);
                if(move == 'R') y--;
                else if(move == 'L') y++;
                else if(move == 'U')x++;
                else if(move == 'D') x--;
            }

            reverse(path.begin(),path.end());

            cout << "YES\n";

            cout << path.size() << endl;

            cout << path << endl;
            return ;
        }

        for (auto move : dir)
        {
            auto [dx, dy, direction] = move;
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#' && !vis[nx][ny])
            {
                parent[nx][ny] = direction;
                pq.push({nx, ny});
                vis[nx][ny] = true;
            }
        }
    }

    cout << "NO\n";
}

int main()
{
    int t = 1;
    // cin>>t;
    while (t--)
    {
        MahavirCoder();
    }
}