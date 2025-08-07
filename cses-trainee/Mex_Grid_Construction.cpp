// Jai shree Ram
// Shivam verma

#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include<iostream>
#include<map>
#include<set>
using namespace std;

 
// some common Defination

const long long INF = LLONG_MAX;
#define ll long long int
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define vc vector<ll>
typedef pair<int,int> pi;
const int mod = 1000000007;
const int N = 1e5;
#define endl "\n" 
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sloop(i,a,b) for (int i = a; i < b; i++)
#define loop(i,b) for (int i = 0; i < b; i++)
#define rloop(i,a,b) for (int i = a; i >= b; i--)
#define print(str) cout << str << "\n"


void MahavirCoder(){
    int n;cin>>n;

    vector<vector<int>> grid(n,vector<int>(n));

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            
            if(i == 0 && j==0){
                grid[0][0] = 0;
                continue;
            }
            
            set<int> mex;
            // Left Most
            for(int row = 0 ; row < i ; row++){
                mex.insert(grid[row][j]);
            }
            // Above 
            for(int col = 0 ; col < j ; col++){
                mex.insert(grid[i][col]);
            }

            // Mex Finding 

            int st = 0;
            for(auto e : mex){
                if( e == st)st++;
                else break;
            }
            grid[i][j] = st;
        }
    }

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j < n ; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int t = 1;
    while(t--){
        MahavirCoder();
    }
}