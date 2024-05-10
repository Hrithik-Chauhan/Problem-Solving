#include<bits/stdc++.h>
using namespace std;
class DSU {
public:
vector<int> parent;
    vector<int> rank;
    DSU(int numNodes){
        parent.resize(numNodes);
        rank.resize(numNodes);
        for(int i=0; i<numNodes; i++){
            parent[i] = -1;
            rank[i] = 1;
        }
    }
    int find(int node){
        if(parent[node] < 0)
            return node;
        return parent[node] = find(parent[node]);
    }
    bool unionNodes(int u, int v){
        int p1 = find(u);
        int p2 = find(v);
        if(p1 == p2) return false;
        if(rank[p1] <= rank[p2]){
            parent[p1] = p2;
            rank[p2] += rank[p1];
        }
        else{
            parent[p2] = p1;
            rank[p1] += rank[p2];
        }
        return true;
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int remove = 0;
        DSU dsu(n+1);
        for(vector<int>& edge: edges)
            if(edge[0] == 3 && !dsu.unionNodes(edge[1],edge[2]))
                    remove++;
        vector<int> a(dsu.parent), b(dsu.parent);
        for(vector<int>& edge: edges) {
            if(edge[0] == 1 && !dsu.unionNodes(edge[1],edge[2]))
                    remove++;
            else if(edge[0] == 2 && !dsu.unionNodes(edge[1],edge[2]))
                    remove++;
        }
        int groupa = 0, groupb = 0;
        for(int i = 1; i <= n; i++) {
            if(a[i] < 0)
                groupa++;
            if(b[i] < 0)
                groupb++;
        }
        if(groupa > 1 || groupb > 1)
            return -1;
        return remove;
    }
};
int main(){
   Solution s;
   int n;
   cin>>n;
   vector<vector<int>> edges;
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin>>edges[i][j];
        }
    }
    int ans=s.maxNumEdgesToRemove(n,edges);
    cout<<ans;
    return 0;

}