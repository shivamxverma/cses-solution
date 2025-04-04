// Jai shree Ram
// Shivam verma

#include<bits/stdc++.h>
using namespace std;
#define int long long int

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = n - 1; i >= 0; i--) {
        for (int prevIdx = i - 1; prevIdx >= -1; prevIdx--) {
            int take = 0;
            if (prevIdx == -1 || nums[i] > nums[prevIdx]) {
                take = 1 + dp[i + 1][i + 1 - (prevIdx == -1 ? 0 : 1)];
            }
            int notTake = dp[i + 1][prevIdx + 1];

            dp[i][prevIdx + 1] = max(take, notTake);
        }
    }
    return dp[0][0];
}

void MahavirCoder(){
  int n;cin>>n;
  vector<int> v(n);
  for(int i=0 ; i<n ; i++){
    cin>>v[i];
  }
  cout << lengthOfLIS(v);
}

signed main(){
    int t = 1;
    while(t--){
        MahavirCoder();
    }
}