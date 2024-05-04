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
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        DSU dsu(n);

        for (int i = 0; i < n; i += 2) {
            dsu.unionNodes(row[i], row[i + 1]);
        }

        int res = 0;
        for (int i = 0; i < n; i += 2) {
            if (dsu.find(i) != dsu.find(i + 1)) {
                res++;
                dsu.unionNodes(i, i + 1);
            }
        }
        return res;
    }
};

int main() {
    Solution s;

    int n;
    cin >> n;
    vector<int> edges(n);
    for (int i = 0; i < n; i++) {
        cin >> edges[i];
    }
    int ans = s.minSwapsCouples(edges);
    cout << ans;

    return 0;
}
