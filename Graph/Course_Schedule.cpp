#include <bits/stdc++.h>
using namespace std;


bool dfsCycle(int node, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &recStack) {
    vis[node] = true;
    recStack[node] = true;

    for (int neighbor : adj[node]) {
        if (!vis[neighbor]) {
            if (dfsCycle(neighbor, adj, vis, recStack)) return true;
        }
        else if (recStack[neighbor]) {
            // Cycle detected
            return true;
        }
    }

    recStack[node] = false;
    return false;
}

bool isCyclic_DFS(int V, vector<vector<int>> &adj) {
    vector<bool> vis(V, false), recStack(V, false);

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (dfsCycle(i, adj, vis, recStack)) return true;
        }
    }

    return false;
}

// Function to perform DFS and topological sorting
void topologicalSortUtil(int v, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st)
{

    // Mark the current node as visited
    visited[v] = true;

    // Recur for all adjacent vertices
    for (int i : adj[v])
    {
        if (!visited[i])
            topologicalSortUtil(i, adj, visited, st);
    }

    // Push current vertex to stack which stores the result
    st.push(v);
}

vector<vector<int>> constructadj(int V, vector<vector<int>> &edges)
{

    vector<vector<int>> adj(V);
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
    }

    return adj;
}

// Function to perform Topological Sort
vector<int> topologicalSort(int V, vector<vector<int>> &edges)
{

    // Stack to store the result
    stack<int> st;

    vector<bool> visited(V, false);
    vector<vector<int>> adj = constructadj(V, edges);
    // Call the recursive helper function to store
    // Topological Sort starting from all vertices one by
    // one
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            topologicalSortUtil(i, adj, visited, st);
    }

    vector<int> ans;

    // Append contents of stack
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

int main()
{
    vector<vector<int>> edges;
	int n,m;cin>>n>>m;
	for(int i=0 ; i<m ; i++){
		int u,v;cin>>u>>v;
		edges.push_back({u-1,v-1});
	}

    vector<vector<int>> adj = constructadj(n, edges);
    if (isCyclic_DFS(n, adj)) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<int> ans = topologicalSort(n, edges);

    for (auto node : ans)
    {
        cout << node+1 << " ";
    }
    cout << endl;

    return 0;
}
