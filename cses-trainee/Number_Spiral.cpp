// Jai shree Ram
// Shivam verma

#include<bits/stdc++.h>
using namespace std;

void MahavirCoder(){
    long long int x,y;cin>>x>>y;
    long long int xx = max(x, y);
    long long int ans;

    if (xx % 2 == 0) {
        if (x == xx) {
            ans = (xx * xx) - (y - 1);
        } else {
            ans = ((xx - 1) * (xx - 1)) + x;
        }
    } else {
        if (y == xx) {
            ans = (xx * xx) - (x - 1);
        } else {
            ans = ((xx - 1) * (xx - 1)) + y;
        }
    }

    cout << ans << endl;
}
int main(){
    int t = 1;
    cin>>t;
    while(t--){
        MahavirCoder();
    }
}