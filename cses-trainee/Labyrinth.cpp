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
const int N = 1e3+5;
#define endl "\n"
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define loop(i, a, b) for (int i = a; i < b; i++)
#define Loop(i, b) for (int i = 0; i < b; i++)
#define Rloop(i, a, b) for (int i = a; i >= b; i--)
#define print(str) cout << str << "\n"

vector<string> grid(N);
vector<tuple<int,int,char>> dir = {{1,0,'D'},{0,1,'R'},{-1,0,'U'},{0,-1,'L'}};
int n,m;
string path;

void solve(int i,int j){
    queue<pair<int,pair<int,string>>> pq;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    pq.push({i,{j,""}});
    visited[i][j] = true;
    int bx = -1, by = -1;

    while(!pq.empty()){
        auto [x, y] = pq.front();
        pq.pop();

        if(grid[x][y.first] == 'B'){
            path = y.second;
            break;
        }
        for(auto [dx, dy, label] : dir){
            int nx = x + dx;
            int ny = y.first + dy;
            if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]!='#' && !visited[nx][ny]){
                string new_path = y.second + label;
                pq.push({nx, {ny, new_path}});
                visited[nx][ny] = true;
            }
        }
    }
}

void MahavirCoder()
{
    cin>>n>>m;
    for(int i=0 ; i<n ; i++)cin>>grid[i];
    
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(grid[i][j] == 'A'){
                solve(i,j);
                break;
            }
        }
    }

    if(path.size() == 0){
        cout << "NO\n";
    } else {
        cout << "YES\n";
        cout << path.size() << endl;
        cout << path << endl;
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