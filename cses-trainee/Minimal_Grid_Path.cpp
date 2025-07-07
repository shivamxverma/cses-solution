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
const int N = 1e5;
#define endl "\n"
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define loop(i, a, b) for (int i = a; i < b; i++)
#define Loop(i, b) for (int i = 0; i < b; i++)
#define Rloop(i, a, b) for (int i = a; i >= b; i--)
#define print(str) cout << str << "\n"

int dx[] = {0, 1};
int dy[] = {1, 0};

void MahavirCoder() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    priority_queue<pair<string, pair<int, int>>, vector<pair<string, pair<int, int>>>, greater<>> pq;

    pq.push({string(1, grid[0][0]), {0, 0}});

    while (!pq.empty()) {
        auto [path, coord] = pq.top();
        pq.pop();
        int x = coord.first;
        int y = coord.second;

        if (visited[x][y]) continue;
        visited[x][y] = true;

        if (x == n - 1 && y == n - 1) {
            cout << path << "\n";
            return;
        }

        for (int dir = 0; dir < 2; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < n && ny < n && !visited[nx][ny]) {
                pq.push({path + grid[nx][ny], {nx, ny}});
            }
        }
    }
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