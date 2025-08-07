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

set<string> ans;

void Solve(int i, string& s) {
    if (i == s.size()) {
        ans.insert(s);
        return;
    }

    for (int j = i; j < s.size(); j++) {
        swap(s[i], s[j]);
        Solve(i + 1, s);
        swap(s[i], s[j]); 
    }
}

void MahavirCoder(){
    string s;cin>>s;
    Solve(0,s);

    cout << ans.size() << endl;

    for(auto k : ans)cout << k << endl;
}

int main(){
    int t = 1;
    while(t--){
        MahavirCoder();
    }
}