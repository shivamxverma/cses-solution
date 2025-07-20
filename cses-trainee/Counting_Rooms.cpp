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
vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
int n,m;

void solve(int i,int j){
    for(auto [x,y] : dir){
        int nx = i+x;
        int ny = j+y;
        if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]!='#'){
           grid[nx][ny] = '#';
           solve(nx,ny);
        }
    }
}

void MahavirCoder()
{
    cin>>n>>m;
    for(int i=0 ; i<n ; i++)cin>>grid[i];

    int ans = 0;

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(grid[i][j]!='#'){
                solve(i,j);
                ans++;
            }
        }
    }
    cout << ans << endl;
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