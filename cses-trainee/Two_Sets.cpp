// Jai shree Ram

#include<bits/stdc++.h>
using namespace std;

void MahavirCoder(){
    int n;cin>>n;
    long long int sum = (n*(1ll)*(n+1))/2;
    if(sum%2==1){
        cout << "NO\n";
        return ;
    }
    long long int tot = sum/2;

    // cout << tot << endl;
    set<int> a;
    for(int i=1 ; i<=n ; i++)a.insert(i);

    set<int> b;

    long long xx = tot;

    for(int i=n ; i>=1 ; i--){
        if(xx>=i){
            xx-=i;
            b.insert(i);
            a.erase(i);
        } else if(xx<i && xx>0){
            b.insert(xx);
            a.erase(xx);
            break;
        }
    }

    cout << "YES\n";

    cout << a.size() << endl;

    for(auto x : a)cout << x << " ";
    cout << endl;


    cout << b.size() << endl;

    for(auto y : b)cout << y << " ";
    cout << endl;

}
int main(){
    int t = 1;
    // cin>>t;
    while(t--){
        MahavirCoder();
    }
}