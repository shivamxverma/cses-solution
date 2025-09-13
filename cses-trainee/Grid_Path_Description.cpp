// Jai shree Ram
// Shivam verma

#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
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

// Inbuilt Function

#define sum(a) (accumulate((a).begin(), (a).end(), 0LL))
#define unique_el(s) \
    sort(all(s));    \
    s.erase(unique(s.begin(), s.end()), s.end())
#define minel(a) (*min_element((a).begin(), (a).end()))
#define maxel(a) (*max_element((a).begin(), (a).end()))
#define mini(a) (min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a) (max_element((a).begin(), (a).end()) - (a).begin())
#define cnt(a, x) (count((a).begin(), (a).end(), (x)))
#define lob(a, x) (lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define upb(a, x) (upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

// input array

template <class T>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &vl : v)
    {
        in >> vl;
    }
    return in;
}
template <typename T>
void pvec(vector<T> &v)
{
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

// output array

template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    for (const auto &i : v)
    {
        out << i << " ";
    }
    return out;
}

// Prefix sum

template <typename T>
void prefixSum(const vector<T> &arr, vector<T> &prefix)
{
    int n = arr.size();
    prefix.resize(n);
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }
}

int ans = 0;
string s;
int n;

map<char, pair<int, int>> dir = {
    {'D', {1, 0}},
    {'R', {0, 1}},
    {'U', {-1, 0}},
    {'L', {0, -1}}};

bool Isvalid(int x, int y)
{
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

bool vis[8][8];

int Solve(int i, int x, int y)
{
    if (x < 0 || x >= 8 || y < 0 || y >= 8 || vis[x][y])
        return 0;
    if (i == s.length())
        return (x == 7 && y == 1);

    if (x == 7 && y == 1)
        return 0;

    vis[x][y] = true;
    int moves = 0;

    if (s[i] == '?')
    {
        for (auto [c, point] : dir)
        {
            auto [dx, dy] = point;
            int nx = x + dx, ny = y + dy;
            moves += Solve(i + 1, nx, ny);
        }
    }
    else
    {
        auto [dx, dy] = dir[s[i]];
        int nx = x + dx, ny = y + dy;
        moves += Solve(i + 1, nx, ny);
    }
    return moves;
}

void MahavirCoder()
{
    cin >> s;
    n = s.size();
    memset(vis, 0, sizeof(vis));
    ans = Solve(0, 1, 1);
    cout << ans << endl;
}

int main()
{
    int t = 1;
    // cin>>t;
    while (t--)
    {
        MahavirCoder();
    }
}