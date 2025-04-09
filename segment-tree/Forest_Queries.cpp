#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
    int n,k;cin>>n>>k;
    vector<vector<int>> pre(n+1,vector<int>(n+1,0));
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            char c;cin>>c;
            pre[i][j] = pre[i][j-1]+pre[i-1][j] + (c=='*') - pre[i-1][j-1];
        }
    }
    while(k--){
        int x1,y1;cin>>x1>>y1;
        int x2,y2;cin>>x2>>y2;
        int ans = pre[x2][y2] - pre[x1-1][y2] - pre[x2][y1-1] + pre[x1-1][y1-1];
        cout << ans << endl;
    }
}

int main(){
  solve();
  return 0;
}



