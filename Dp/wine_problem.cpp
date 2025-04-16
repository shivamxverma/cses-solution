// Jai shree Ram
// Shivam verma

#include<bits/stdc++.h>
using namespace std;
 
int solve(int i,int j,vector<int> &wines,int year,vector<vector<int>> &memo){
    if(i==j) return wines[i]*year;
    if(i>j) return 0;
    else if(memo[i][j]!=0)return memo[i][j];
    int left = wines[i]*year + solve(i+1,j,wines,year+1,memo);
    int right = wines[j]*year + solve(i,j-1,wines,year+1,memo);
    return memo[i][j] = max(left,right);
}

void MahavirCoder(){
    int n;cin>>n;
    vector<int> wines(n);
    for(int i=0 ; i<n ; i++){
        cin>>wines[i];
    }
    vector<vector<int>> memo(n+1,vector<int>(n+1,0));
    cout << solve(0,n-1,wines,1,memo) << endl;
}
int main(){
    int t = 1;
    // cin>>t;
	while(t--){
		MahavirCoder();
	}
	return 0;
}