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

ll mini = INT_MAX;

void Solve(int i,vector<int> &a,ll target,ll var){
    if( i == a.size() )return ;
    var += a[i];
    ll score = abs(target-2*var);
    mini = min(mini,score);
    Solve(i+1,a,target,var);
    var -= a[i];
    Solve(i+1,a,target,var);
}

void MahavirCoder(){
   int n;cin>> n;
   vector<int> a(n);
   ll sum = 0;
   for(int i=0 ; i<n ; i++){
      cin>>a[i];
      sum += a[i];
   }

   Solve(0,a,sum,0);

   cout << mini << endl;

}

int main(){
    int t = 1;
    while(t--){
        MahavirCoder();
    }
}