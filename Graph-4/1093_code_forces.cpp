#include <iostream>
#include <vector>
#include <queue>
#define MOD 998244353
using namespace std;

vector<vector<int>> adj;
vector<int> color;
long long count1, count2;

void bfs(int src) {
    queue<int> q;
    q.push(src);
    color[src] = 1;
    count1++;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (color[v] == 0) {
                q.push(v);
                color[v] = 3 - color[u];
                if (color[v] == 1) count1++;
                else count2++;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    color.resize(3);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    long long ans = 1;

    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {
            count1 = count2 = 0;
            bfs(i);
            ans = (ans * ((count1 == 0 && count2 == 0) ? 2 : (count1 + count2))) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}
