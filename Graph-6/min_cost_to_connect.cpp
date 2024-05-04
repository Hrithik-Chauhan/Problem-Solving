#include<bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent;

    DSU(int numNodes) {
        parent.assign(numNodes, -1);
    }

    int find(int node) {
        if (parent[node] == -1) return node;
        return parent[node] = find(parent[node]);
    }

    bool unionNodes(int u, int v) {
        int p1 = find(u);
        int p2 = find(v);
        if (p1 == p2) return false;

        parent[p1] = p2;
        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> adj;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                int distance = abs(x1 - x2) + abs(y1 - y2);
                adj.push_back({distance, i, j});
            }
        }
        sort(adj.begin(), adj.end());
        DSU dsu(n);
        int ans = 0;
        for (auto edge : adj) {
            int distance = edge[0], u = edge[1], v = edge[2];
            if (dsu.unionNodes(u, v)) {
                ans += distance;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    int ans = s.minCostConnectPoints(points);
    cout <<ans ;
    return 0;
}
