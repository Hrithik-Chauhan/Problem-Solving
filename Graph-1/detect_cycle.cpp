#include<bits/stdc++.h>
using namespace std;

bool checkCycle(int node, vector <vector< int >> adj, vector<bool>& vis, vector<bool>& dfsVis) {
      vis[node] = 1;
      dfsVis[node] = 1;
      for (auto it: adj[node]) {
        if (!vis[it]) {
          if (checkCycle(it, adj, vis, dfsVis)) return true;
        } else if (dfsVis[it]) {
          return true;
        }
      }
      dfsVis[node] = 0;
      return false;
    }
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
         vector<bool> visited(V,0);
         vector<bool> dfsvis(V,0);
         for (int i = 0; i < V; i++) {
        if (!visited[i]) {
          // cout << i << endl; 
          if (checkCycle(i, adj, visited, dfsvis)) {
             // cout << i << endl;
            return true;
          }
        }
      }
      return false;
    }
      int main(){
        int source,destination,n;
        cout<<"Enter No of edges:\n";
        cin>>n;
        vector<vector<int>> adj(n,vector<int>(2));
        cout<<"enter the edges:\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                cin>>adj[i][j];
            }
        }
        if(isCyclic(n,adj))cout<<"There is a cycle in graph!!\n";
        else cout<<"There is no cycle in graph!!\n";

        return 0;
    }
