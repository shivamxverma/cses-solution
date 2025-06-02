// Jai shree Ram

#include<bits/stdc++.h>
using namespace std;

void MahavirCoder(){
    int n;cin>>n;
    vector<pair<int,int>> entry;

    for(int i=0 ; i<n ; i++){
        int x,y;cin>>x>>y;
        entry.push_back({x,1});
        entry.push_back({y,-1});
    }


    sort(entry.begin(),entry.end());

    int maxp = 0;

    int present = 0;

    for(auto [pos,val] : entry){
        present += val;
        maxp = max(maxp,present);
    }

    cout << maxp << endl;
}

int main(){
    int t = 1;
    // cin>>t;
    while(t--){
        MahavirCoder();
    }
}