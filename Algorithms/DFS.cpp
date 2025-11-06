#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1005];
vector<bool> vis(1005, false);
void dfs(int src)
{
    cout << src << " ";
    vis[src] = true;
    for (int x : adj[src])
    {
        if (!vis[x])
        {
            dfs(x);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int src;
    cin >> src;
    dfs(src);

    return 0;
}
