#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
 
#define int long long
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define vi vector<int>
typedef pair<int,int> pi;
#define setbits(x) __builtin_popcountll(x)
#define binary_rep(x) bitset<sizeof(10)*8> binary_rep(x)
const int M = 1000000007;
#define endl "\n" 
#define sum(a) (accumulate((a).begin(), (a).end(), 0LL))
#define unique_el(s) sort(all(s)) ; s.erase(unique(s.begin(), s.end()), s.end())
#define minel(a) (*min_element((a).begin(), (a).end()))
#define maxel(a) (*max_element((a).begin(), (a).end()))
#define mini(a) (min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a) (max_element((a).begin(), (a).end()) - (a).begin())
#define cnt(a, x) (count((a).begin(), (a).end(), (x)))
#define lob(a, x) (lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define upb(a, x) (upper_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for (int i = a; i < b; i++)
#define Rep(i,b) for (int i = 0; i < b; i++)
#define repr(i,a,b) for (int i = a; i >= b; i--)
#define printyes cout << "YES" << "\n" 
#define printno cout << "NO" << "\n" 
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
template <class T> void _print(T t){cerr<<t;}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
 
template <class T> istream & operator>> (istream &in, vector<T> &v) {
    for (auto &vl : v) { in >> vl;} return in; }
template <typename T> void pvec(vector<T>&v) {
    for(auto i : v) {cout << i << " ";} cout << endl;}

bool yes = false;
vector<vector<char>> parentDir;

void bfs(int i, int j, vector<string> &g, vector<vector<bool>> &vis, vector<char> &ans) {
    int n = g.size();
    int m = g[0].size();
    queue<pair<int,int>> q;
    q.push({i,j});
    
    vector<pair<int,int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<char> dirLabels = {'U', 'D', 'L', 'R'};
    
    while (!q.empty()) {
        pair<int,int> node = q.front();
        q.pop();
        int x = node.first;
        int y = node.second;

        for (int d = 0; d < 4; d++) { 
            int newx = x + directions[d].first;
            int newy = y + directions[d].second;

            if (newx < 0 || newx >= n || newy < 0 || newy >= m) continue;

            if (!vis[newx][newy] && g[newx][newy] != '#') {
                vis[newx][newy] = true;
                parentDir[newx][newy] = dirLabels[d];
                q.push({newx, newy});
                if (g[newx][newy] == 'B') {
                    yes = true;
                    return;
                }
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int sx, sy;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 'A') {
                sx = i;
                sy = j;
            }
        }
    }

    vector<char> ans;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    parentDir = vector<vector<char>>(n, vector<char>(m, ' '));
    
    bfs(sx, sy, v, vis, ans);
    if (!yes) {
        cout << "NO" << endl;
        return;
    }
    pair<int, int> end;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 'B') {
                end = {i, j};
                break;
            }
        }
    }

    pair<int, int> curr = end;
    while (v[curr.first][curr.second] != 'A') {
        ans.push_back(parentDir[curr.first][curr.second]);
        if (parentDir[curr.first][curr.second] == 'U') curr.first++;
        else if (parentDir[curr.first][curr.second] == 'D') curr.first--;
        else if (parentDir[curr.first][curr.second] == 'L') curr.second++;
        else if (parentDir[curr.first][curr.second] == 'R') curr.second--;
    }
    reverse(ans.begin(), ans.end());

    cout << "YES" << endl;
    cout << ans.size() << endl;
    for (char c : ans) {
        cout << c;
    }
    cout << endl;
}

signed main(){
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
}