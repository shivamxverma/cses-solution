#include <bits/stdc++.h>
using namespace std;

long long int minCoinSum(vector<long long int> &coins) {
    sort(coins.begin(), coins.end());
    long long int val = 1;
    for(auto i:coins) {
        if(i > val)
            return val;
        val += i;
    }
    return val;
}

int main() {
    int n;cin>> n;
    vector<long long int> coins(n);
    for(int i=0 ; i<n ; i++)cin>>coins[i];
    cout << minCoinSum(coins);
    return 0;
}