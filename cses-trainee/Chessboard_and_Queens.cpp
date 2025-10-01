// Jai shree Ram
// Shivam verma

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <map>
#include <set>
using namespace std;

// some common Defination

const long long INF = LLONG_MAX;
#define ll long long int
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define vc vector<ll>
typedef pair<int, int> pi;
const int mod = 1000000007;
const int N = 1e5;
#define endl "\n"
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sloop(i, a, b) for (int i = a; i < b; i++)
#define loop(i, b) for (int i = 0; i < b; i++)
#define rloop(i, a, b) for (int i = a; i >= b; i--)
#define print(str) cout << str << "\n"

char grid[9][9];
int ct = 0;

bool CanPlace(int x, int y)
{
    int nx = x, ny = y;

    while (nx--)
        if (grid[nx][ny] == 'Q')
            return false;

    nx = x; ny = y;
    while (nx-- && ny--)
        if (grid[nx][ny] == 'Q')
            return false;

    nx = x; ny = y;
    while (nx-- && ny++ < 8)
        if (grid[nx][ny] == 'Q')
            return false;

    return true;
}

ll Solve(int row)
{
    if (row == 9)
        return 1;

    ll ways = 0;
    for (int col = 1; col <= 8; col++)
    {
        if (CanPlace(row, col) && grid[row][col] != '*')
        {
            grid[row][col] = 'Q';
            ways += Solve(row + 1);
            grid[row][col] = '.'; 
        }
    }
    return ways;
}

int main()
{
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            cin >> grid[i][j];
        }
    }

    cout << Solve(1) << endl;

    return 0;
}
