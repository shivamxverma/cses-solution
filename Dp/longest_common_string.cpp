// Jai shree Ram
// Shivam verma

#include<bits/stdc++.h>
#include<iostream>
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
#define loop(i,a,b) for (int i = a; i < b; i++)
#define Loop(i,b) for (int i = 0; i < b; i++)
#define Rloop(i,a,b) for (int i = a; i >= b; i--)
#define print(str) cout << str << "\n"

// Inbuilt Function

#define sum(a) (accumulate((a).begin(), (a).end(), 0LL))
#define unique_el(s) sort(all(s)) ; s.erase(unique(s.begin(), s.end()), s.end())
#define minel(a) (*min_element((a).begin(), (a).end()))
#define maxel(a) (*max_element((a).begin(), (a).end()))
#define mini(a) (min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a) (max_element((a).begin(), (a).end()) - (a).begin())
#define cnt(a, x) (count((a).begin(), (a).end(), (x)))
#define lob(a, x) (lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define upb(a, x) (upper_bound((a).begin(), (a).end(), (x)) - (a).begin())
 

void MahavirCoder(){
    int n,m;cin>>n>>m;
    string s;
    string t;
    cin>>s>>t;

    vector<vector<int>> dp(n+1,vector<int>(n+1,0));

    for(int i=0 ; i<n ; i++)dp[i][0] = 0;
    for(int i=0 ; i<m ; i++)dp[0][i] = 0;

    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            if(s[i-1]==t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            
            } else {
                dp[i][j] = 0;
            }
        }
    }

    cout << dp[n][m] << endl;

}
int main(){
    int t = 1;
    // cin>>t;
	while(t--){
		MahavirCoder();
	}
	return 0;
}