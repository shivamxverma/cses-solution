#include <bits/stdc++.h>
using namespace std;

bool isValid(int x, int y, vector<vector<bool>> &vis, vector<string> &graph) {
    int n = graph.size();
    int m = graph[0].size();
    return x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && graph[x][y] != '#';
}

// Directions: {dx, {dy, direction}}
vector<pair<int, pair<int, char>>> dir = {
    {0, {-1, 'L'}}, {0, {1, 'R'}}, {1, {0, 'D'}}, {-1, {0, 'U'}}
};

vector<vector<pair<int, int>>> parent;

void bfs(int i, int j, vector<string> &graph) {
    int n = graph.size();
    int m = graph[0].size();
    
    parent.assign(n, vector<pair<int, int>>(m, {-1, -1}));  // Initialize with {-1, -1}
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<char>> move(n, vector<char>(m, 0)); // Store movement directions
    vis[i][j] = true;

    pair<int, int> last = {-1, -1};
    queue<pair<int, int>> pq;
    pq.push({i, j});

    while (!pq.empty()) {
        auto [x, y] = pq.front();
        pq.pop();

        if (graph[x][y] == 'B') {
            last = {x, y};
            break;
        }

        for (auto it : dir) {
            int nx = x + it.first;
            int ny = y + it.second.first;

            if (isValid(nx, ny, vis, graph)) {
                vis[nx][ny] = true;
                move[nx][ny] = it.second.second;
                parent[nx][ny] = {x, y};
                pq.push({nx, ny});
            }
        }
    }

    if (last.first == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        string path = "";
        pair<int, int> cur = last;

        while (cur != make_pair(i, j)) {
            path.push_back(move[cur.first][cur.second]);
            cur = parent[cur.first][cur.second];
        }

        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        cout << path << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> graph(n);
    for (int i = 0; i < n; i++) {
        cin >> graph[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 'A') {
                bfs(i, j, graph);
                return 0;
            }
        }
    }

    cout << "NO\n";
}
