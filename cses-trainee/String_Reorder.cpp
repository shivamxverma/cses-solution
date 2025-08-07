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
    string s;cin>>s;
    sort(s.begin(),s.end());

    string news = s;
    int n = s.size();

    for(int cur = 1 ; cur<n ; cur++){
        if(s[cur-1] == s[cur]){
            auto it = upper_bound(news.begin(),news.end(),s[cur]);
            if(it != news.end()){
                int k = it-news.begin();
                swap(s[cur+1],s[k]);
            }
        }
    }

    cout << s << endl;

}

int main(){
    int t = 1;
    while(t--){
        MahavirCoder();
    }
}