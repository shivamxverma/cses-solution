
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const int MOD=1000000007;
map<ll,ll> f;

ll fib(ll n)
{
    if(f.count(n)) return f[n];
    if(n==0) return 0;
    if(n==1 || n==2) return 1;
    if(n%2==0)
    {
        ll k=n/2;
        ll ret1=fib(k-1),ret2=fib(k);
        return f[n]=((((2ll*ret1)%MOD+ret2)%MOD)*ret2)%MOD;
    }
    else
    {
        ll k=(n+1)/2;
        ll ret1=fib(k-1),ret2=fib(k);
        return f[n]=( (ret1*ret1)%MOD + (ret2*ret2)%MOD)%MOD;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    cout<<fib(n);
}