// Jai shree Ram

#include<bits/stdc++.h>
using namespace std;

void MahavirCoder(){
    int n,m; cin>>n>>m;
    multiset<int> tickets;

    for(int i=0 ; i<n ; i++){
        int x;cin>>x;
        tickets.insert(x);
        // cout << x << endl;
    }

    for(int i=0 ; i<m ; i++){
        int x;cin>>x;
        // cout << x << endl;
        auto it = tickets.lower_bound(x);

        // cout << *it << endl;
        if(tickets.size() == 0){
            cout << -1 << endl;
        }
        else if(it == tickets.begin()){
            if(*it > x)cout << -1 << endl;
            else {
                cout << (*it) << endl;
                tickets.erase(it);
            }
        } else {
            if(it == tickets.end()){
                cout << *(--it) << endl;
                tickets.erase(it);
            } else {
                if(*it == x){
                    cout << x << endl;
                    tickets.erase(it);
                } else {
                    cout << *(--it) << endl;
                    tickets.erase(it);
                } 
            }
        }
    }
}

int main(){
    int t = 1;
    // cin>>t;
    while(t--){
        MahavirCoder();
    }
}