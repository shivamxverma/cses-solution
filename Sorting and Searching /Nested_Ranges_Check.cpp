#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,pair<int,int>> &a,pair<int,pair<int,int>> &b){
    if(a.first == b.first) return a.second.first > b.second.first;
    return a.first < b.first;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int,pair<int,int>>> ranges;

    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        ranges.push_back({x, {y, i}});
    }

    sort(ranges.begin(), ranges.end(), cmp);

    vector<int> ans1(n), ans2(n);

    int mn = 0, mx = 0;

    for(int i = 0; i < n - 1; i++){
        auto [a, b] = ranges[i];
        auto [c, d] = ranges[i + 1];
        mn = min(mn, a);
        mx = max({mx, b.first, d.first});

        if(a <= c && d.first <= b.first){
            ans1[b.second]++;
        }
        if(c >= mn && d.first <= mx){
            ans2[d.second]++;
        }
    }

    for(auto xx : ans1){
        cout << xx << " ";
    }
    cout << endl;
    for(auto xx : ans2){
        cout << xx << " ";
    }
    cout << endl;

    return 0;
}
