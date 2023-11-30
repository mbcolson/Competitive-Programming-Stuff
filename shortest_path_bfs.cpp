#include <bits/stdc++.h>
using namespace std;

/* Compute the Shortest Path From A Node To All 
   Other Nodes in an Unweighted Graph Using 
   Breadth-First Search */

int main() {
    vector<vector<int>> edges;
    const int n = 11;          // n is the number of nodes in the graph
    
    edges.push_back({0, 1});
    edges.push_back({1, 2});
    edges.push_back({2, 3});
    edges.push_back({2, 4});
    edges.push_back({3, 6});
    edges.push_back({4, 5});
    edges.push_back({5, 6});
    edges.push_back({5, 7});
    edges.push_back({6, 8});
    edges.push_back({7, 10});
    edges.push_back({8, 9});
    
    vector<int> adj[n];
        
    for(auto edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
        
    queue<int> q;
    vector<int> d(n, INT_MAX);
    q.push(0);
    d[0] = 0;
        
    while(!q.empty()) {
        int current = q.front();
        q.pop();
            
        for(int v : adj[current]) {
            if (d[v] == INT_MAX) {
                d[v] = d[current] + 1;
                q.push(v);
            }
        }
    }

    /* At this point, the vector d contains the shortest path
       distance (least number of hops) between node 0 and every
       other node in the graph. */

    for(int i = 0; i < n; i++)
        cout << d[i] << ' ';

    return 0;
}
