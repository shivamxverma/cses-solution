#include<bits/stdc++.h>
using namespace std;
#define all(s) (s.begin(),s.end())

void solve(){
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    string ans = "";
    string odd = "";
    int n = s.size();
    bool ok = true;
    
    for(int i = 0; i < n; i++){
        int j = i;
        while(j < n && s[i] == s[j]){
            j++;
        }
        if((j - i) % 2 == 1){
            if(ok) ok = false;
            else {
                cout << "NO SOLUTION\n";
                return;
            }
            odd = s.substr(i, j - i);
        } else {
            ans += s.substr(i, (j - i) / 2);
        }
        i = j - 1;
    }
    
    string re = ans;
    reverse(re.begin(), re.end());
    cout << ans + odd + re << endl;
}

signed main(){
    int t = 1;
    while(t--){
        solve();
    }
}