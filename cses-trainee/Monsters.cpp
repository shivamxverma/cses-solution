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
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    vector<tuple<int, int, char>> dir = {{0, 1, 'R'},{1, 0, 'D'}, {-1, 0, 'U'}, {0, -1, 'L'}};
    queue<pair<int,int>> monsters;
    queue<pair<int,int>> player;
    vector<vector<char>> parent(n , vector<char>(m , '#'));
    vector<vector<int>> monsterDist(n+1,vector<int>(m+1,INT_MAX));
    vector<vector<int>> playerDist(n+1,vector<int>(m+1,INT_MAX));

    int si, sj;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A')
            {
                player.push({i, j});
                playerDist[i][j] = 0;
                si = i;
                sj = j;
            } else if(grid[i][j] == 'M'){
                monsters.push({i,j});
                monsterDist[i][j] = 0;
            }
        }
    }

    


    while(!monsters.empty()){
        auto [x,y] = monsters.front();
        monsters.pop();

        for (auto [dx, dy, label] : dir)
        {
            int nx = x + dx, ny = y + dy;

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#')
            {
                if(monsterDist[nx][ny] > monsterDist[x][y]+1){
                    monsterDist[nx][ny] = monsterDist[x][y]+1;
                    monsters.push({nx, ny});
                }
            }
        }

    }

    while (!player.empty())
    {
        auto [x, y] = player.front();
        player.pop();

        // Path Construction

        if (x == n - 1 || y == m - 1 || x == 0 || y == 0)
        {
            string path = "";
            while (!(x == si && y == sj))
            {
                char move = parent[x][y];
                path.push_back(move);
                if (move == 'R')
                    y--;
                else if (move == 'L')
                    y++;
                else if (move == 'U')
                    x++;
                else if (move == 'D')
                    x--;
            }

            reverse(path.begin(), path.end());

            cout << "YES\n";

            cout << path.size() << endl;

            cout << path << endl;
            return;
        }

        // Actual Logic 

        for (auto [dx, dy, label] : dir)
        {
            int nx = x + dx, ny = y + dy;

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#')
            {
                if(playerDist[x][y]+1 < playerDist[nx][ny] && playerDist[x][y] + 1 < monsterDist[nx][ny]){
                    playerDist[nx][ny] = playerDist[x][y]+1;
                    parent[nx][ny] = label;
                    player.push({nx,ny});
                }
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