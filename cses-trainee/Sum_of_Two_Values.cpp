// Jai shree Ram

#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> &a,pair<int,int> &b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

void MahavirCoder(){
    int n,k;cin>>n>>k;
    vector<pair<int,int>> a(n);
    for(int i=0;  i<n ; i++){
        int x;cin>>x;
        a[i] = {x,i};
    }

    sort(a.begin(),a.end());

    int i = 0,j = n-1;
    while(i<j){
        int sum = a[i].first+a[j].first;
        if(sum == k){
            cout << a[i].second+1 << " " << a[j].second+1 << endl;
            return ;
        } else if(sum < k){
            i++;
        } else {
            j--;
        }
    }

    cout << "IMPOSSIBLE\n";
}

int main(){
    int t = 1;
    // cin>>t;
    while(t--){
        MahavirCoder();
    }
}