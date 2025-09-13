#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define ll long long int

int main()
{
    int n;
    cin >> n;
    vector<vector<string>> ans(n+1);

    ans[0].push_back("");

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < ans[i - 1].size(); j++)
        {
            string newS = "0" + ans[i-1][j];
            ans[i].push_back(newS);
        }

        for (int j = ans[i - 1].size()-1; j >= 0; j--)
        {
            string newS = "1" + ans[i-1][j];
            ans[i].push_back(newS);
        }
    }

    for(auto alls : ans[n])cout << alls << endl;
}