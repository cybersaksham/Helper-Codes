#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> makeGraph(int n, vector<pair<int, int>> edges) {
    vector<vector<int>> graph(n);
    for(int i=0; i<n; i++) {
        vector<int> tmp;
        graph[i] = tmp;
    }

    for(int i=0; i<edges.size(); i++) {
        int a = edges[i].first;
        int b = edges[i].second;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    return graph;
}

void bfs(int n, int root, vector<vector<int>> const &graph) {
    vector<bool> visited(n, false);
    visited[root] = true;

    queue<int> q;
    q.push(root);

    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(auto node:graph[curr]) {
            if(!visited[node]) {
                q.push(node);
                visited[node] = true;
            }
        }
    }
}

void dfsHelper(int root, vector<bool> &visited, vector<vector<int>> &graph) {
    visited[root] = true;
    for(auto node:graph[root]) {
        if(!visited[node]) dfsHelper(node, visited, graph);
    }
}

void dfs(int n, int root, vector<vector<int>> &graph) {
    vector<bool> visited(n, false);
    dfsHelper(root, visited, graph);
}