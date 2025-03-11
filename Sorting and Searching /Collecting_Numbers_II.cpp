// Jai shree Ram
// Shivam verma

#include<bits/stdc++.h>
using namespace std;
 
// some common Defination

const long long INF = LLONG_MAX;
#define ll long long int
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define vc vector<ll>
typedef pair<int,int> pi;
const int mod = 1000000007;
const int N = 2e5;
#define endl "\n" 
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define loop(i,a,b) for (int i = a; i < b; i++)
#define Loop(i,b) for (int i = 0; i < b; i++)
#define Rloop(i,a,b) for (int i = a; i >= b; i--)
#define print(str) cout << str << "\n"

// Inbuilt Function

#define sum(a) (accumulate((a).begin(), (a).end(), 0LL))
#define unique_el(s) sort(all(s)) ; s.erase(unique(s.begin(), s.end()), s.end())
#define minel(a) (*min_element((a).begin(), (a).end()))
#define maxel(a) (*max_element((a).begin(), (a).end()))
#define mini(a) (min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a) (max_element((a).begin(), (a).end()) - (a).begin())
#define cnt(a, x) (count((a).begin(), (a).end(), (x)))
#define lob(a, x) (lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define upb(a, x) (upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

// Bit Manupulatoin operations 

#define bits(x) __builtin_popcount(x)
#define bitsll(x) __builtin_popcountll(x)
#define msb(x) (31 - __builtin_clz(x))
#define msbll(x) (63 - __builtin_clzll(x))
#define lsb(x) __builtin_ctz(x)
#define lsbll(x) __builtin_ctzll(x)

bool check_bit(int x ,int k){return x&(1<<k);}
int set_bit(int x,int k){return x|(1<<k);}
int Unset_bit(int x,int k){return x&(~(1<<k));}
int flip_bit(int x,int k){return x^(1<<k);}

// xor from 1 to N

int XOR1ToN(int n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}

// count the bits

int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += (n & 1);
        n >>= 1;
    }
    return count;
}

// Number Theory 
/*
vector<long long> fact(N + 1), invFact(N + 1);
vector<int> lpf(N + 1);

long long modExp(long long base, long long exp, int mod) {
    long long res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

// Precompute factorials and inverse factorials

void precomputeFactorials() {
    fact[0] = invFact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i % mod;
    }
    invFact[N] = modExp(fact[N], mod - 2, mod);
    for (int i = N - 1; i > 0; i--) {
        invFact[i] = invFact[i + 1] * (i + 1) % mod;
    }
    invFact[0] = 1;
}

// calculate NCR
long long nCr(int n, int r) {
    if (r > n || r < 0) return 0;
    return fact[n] * invFact[r] % mod * invFact[n - r] % mod;
}


void sieve() {
    for (int i = 2; i <= N; i++) {
        if (lpf[i] == 0) {
            for (int j = i; j <= N; j += i) {
                if (lpf[j] == 0) lpf[j] = i;
            }
        }
    }
}

// Graph and Tree

vector<vector<int>> adj(int n,int m){
  vector<vector<int>> graph(n);
  for(int i=0 ; i<m ; i++){
    int u,v;cin>>u>>v;
    u--,v--;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  return graph;
}

// Dfs traversal

void dfs(int start,vector<vector<int>> &adj,vector<bool> &vis,vector<int> &parent){
  vis[start] = true;
  for(auto edge : adj[start]){
    if(!vis[edge]){
      parent[edge] = start;
      dfs(edge,adj,vis,parent);
    }
  }
}

// BFS traversal 

void bfs(int start,vector<vector<int>> &adj,vector<int> &parent,vector<int> &distance){
  distance[start] = 0;
  vector<bool> vis(adj.size(),false);
  queue<int> q;
  q.push(start);
  vis[start] = true;
  while(!q.empty()){
    int node = q.front();
    q.pop();
    for(auto edge : adj[node]){
      if(!vis[edge]){
        vis[edge] = true; 
        distance[edge] = distance[node]+1;
        parent[edge] = node;     
        q.push(edge);
      }
    }
  }
}

// Dijkstra

void Dijkstra(int s, int n, vector<ll> &dist, vector<int> &parent, vector<pair<int, ll>> *adj) {
	dist.assign(n, INF);
	parent.assign(n, -1);
	dist[s] = 0;
	priority_queue <pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
	q.push({0, s});
	while (!q.empty()) {
		pair<ll, int> here = q.top();
		q.pop();
		int v = here.s;
		ll d_v = here.f;
		if (d_v != dist[v])
			continue;
		for (auto edge : adj[v]) {
			if (dist[v] + edge.s < dist[edge.f]) {
				dist[edge.f] = dist[v] + edge.s;
				parent[edge.f] = v;
				q.push({dist[edge.f], edge.f});
			}
		}
	}
}

// dsu

struct UnionFind {
	int n;
	vector<int> rank;
	vector<int> parent;
	UnionFind(int n) {
		rank.resize(n);
		fill(rank.begin(), rank.end(), 0);
		parent.resize(n);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}
	int get(int a) {
		return parent[a] = (parent[a] == a ? a : get(parent[a]));
	}
	void merge(int a, int b) {
		a = get(a);
		b = get(b);
		if (a == b) {
			return;
		}
		if (rank[a] == rank[b]) {
			rank[a]++;
		}
		if (rank[a] > rank[b]) {
			parent[b] = a;
		} else {
			parent[a] = b;
		}
	}
};

// Topological sort
void dfs(int start, vector<int>*edges, bool *visited, vector<int>& ans)
{
	visited[start] = true;
	for (auto i : edges[start])
	{
		if (visited[i])
			continue;
		dfs(i, edges, visited, ans);
	}
	ans.pb(start);
}

vector<int> topo_sort(int n, vector<int>*edges)
{
	vector<int> v1;
	bool *visited = new bool[n]();
	for (int i = 0; i < n; i++)
	{
		if (visited[i])
			continue;
		dfs(i, edges, visited, v1);
	}
	reverse(v1.begin(), v1.end());
	return v1;
}

// BellmanFord 

void BellmanFord(int n, int src, vector<pair<int, ll>> *edges, vector<ll>& dist, set<int>& negCycle) {
	fill(all(dist), INF);
	dist[src] = 0;
	vector<pair<ll, pair<int, int>>> e;
	for (int i = 0; i < n; i++) {
		for (auto j : edges[i]) {
			e.pb({j.s, {i, j.f}});
		}
	}
	for (int i = 0; i < n - 1; i++) {
		for (auto j : e) {
			dist[j.s.s] = min(dist[j.s.s], dist[j.s.f] + j.f);
		}
	}
	//checking negative cycle
	for (int i = 0; i < n; i++) {
		for (auto j : e) {
			if (dist[j.s.s] > dist[j.s.f] + j.f) {
				dist[j.s.s] = dist[j.s.f] + j.f;
				negCycle.insert(j.s.s);
			}
		}
	}
}

// All pair shortest path

void FloydWarshall(int n, vector<pair<int, ll>> *adj, vector<vector<ll>> &dist) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dist[i][j] = INF;
		}
		dist[i][i] = 0;
	}
	for (int i = 0; i < n; i++) {
		for (auto j : adj[i]) {
			dist[i][j.f] = min(dist[i][j.f], j.s);
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dist[i][k] < INF && dist[k][j] < INF) // for updating only when there is a path
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}
*/

// Debug

#ifndef ONLINE_JUDGE
#define shivam(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define shivam(x)
#endif
template <class T> void _print(T t){cerr<<t;}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
 
// input array

template <class T> istream & operator>> (istream &in, vector<T> &v) {
    for (auto &vl : v) { in >> vl;} return in; }
template <typename T> void pvec(vector<T>&v) {
    for(auto i : v) {cout << i << " ";} cout << endl;}

// output array    

template <typename T>
ostream& operator<<(ostream &out, const vector<T>& v) {
    for (const auto &i : v) {
        out << i << " ";
    }
    return out;
}

vector<int> hsh(N,0);

void MahavirCoder() {
    int n,x = 1,q;cin>>n>>q;
    map<int,int> free;
    free[0] = 0;
    vc v(n);cin>>v;
    Loop(i,n)free[v[i]] = i+1;
    for(int i=n ; i>=1 ; i--){
        int ele = v[i-1];
        if(free[ele-1]<i){
          if(hsh[ele]==0){
            hsh[ele] = x;
            hsh[ele-1] = x;
            x++;
          }
          else hsh[ele-1] = hsh[ele]; 
        }
        else {
          if(hsh[ele]==0){
            hsh[ele] = x;
            x++;
          }
        }
    }
    x--;
    while(q--){
        int d,y;cin>>d>>y;
        int before = 0;
        if(free[v[d-1]-1]<d)before++;
        if(free[v[y-1]-1]<y)before++;
        free[v[d-1]] = y;
        free[v[y-1]] = d;
        int after = 0;
        if(free[v[d-1]-1]<y)after++;
        if(free[v[y-1]-1]<d)after++;
        
        if(before < after)x--;
        if(before > after)x++;

        cout << x << endl;
    }
}

int main(){
    int t = 1;
    while(t--){
        MahavirCoder();
    }
}
