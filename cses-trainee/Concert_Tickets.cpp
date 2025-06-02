// Jai shree Ram

#include<bits/stdc++.h>
using namespace std;

void MahavirCoder(){
    int n,m;
    vector<long long> person;
    multiset<int> tickets;
    cin >> n >> m;
    
    person.resize(m);
    for(int i=0 ; i<n ; i++){
        int x;cin>>x;
        tickets.insert(x);
    };
    for(int i=0 ; i<m ; i++)cin>>person[i];

    for(int i=0 ; i<m ; i++){
        int per = person[i];
        auto it = tickets.lower_bound(per);
        if(it != tickets.begin()){
            if(*it == per){
                tickets.erase(it);
                cout << per << endl;
            } else {
                int ele = *(--it);
                cout << ele << endl;
                tickets.erase(ele);
            }
        } else {
            if(*it<=per){
                cout << (*it) << endl;
                tickets.erase(it);
            }else cout << -1 << endl;
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