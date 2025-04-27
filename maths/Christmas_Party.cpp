#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 1;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;cin>>n;

    long long d[n+1];
    d[1]=0;
    d[2]=1;
    for(long long i=3;i<=n;i++)
    {
        d[i]=(((d[i-1]+d[i-2])%MOD)*(i-1))%MOD;
    }
    cout<<d[n];
    return 0;
}
