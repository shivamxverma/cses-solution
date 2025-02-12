// Jai shree Ram
// Shivam verma

#include<bits/stdc++.h>
using namespace std;

void MahavirCoder(){
  int n;
	int x;
	cin>>n>>x;
  vector<int> price(n);
	vector<int> pages(n);

	for (int i = 0; i < n; i++) { cin >> price[i]; }
	for (int i = 0; i < n; i++) { cin >> pages[i]; }
	vector<vector<int>> dp(n+1,vector<int> (x+1));
  
	for(int i = 1 ; i<=n ; i++){
		int curr_cost = price[i - 1];
		int curr_pages = pages[i - 1];
		for(int j=1 ; j<=x ; j++){
			dp[i][j] = dp[i-1][j];
			if(j>=curr_cost)dp[i][j] = max(dp[i][j],curr_pages + dp[i-1][j-curr_cost]);
		}
	}
  
	cout << dp[n][x] << "\n";
}

int main(){
    int t = 1;
    while(t--){
        MahavirCoder();
    }
}