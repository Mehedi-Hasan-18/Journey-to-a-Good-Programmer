#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, e;
    cin >> n >> e;
    vector<int> adj[n + 1];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // int node;cin >> node;
    // cout << adj[node].size();

    queue<pair<int, int>> q;
    vector<bool> vis(n, false);
    bool flag = false;
    int level;
    cin >> level;

    q.push({0, 0});
    vis[0] = true;

    while (!q.empty())
    {
        auto fr = q.front();
        q.pop();

        if (fr.second == level)
        {
            cout << fr.first << " ";
        }

        for (auto x : adj[fr.first])
        {
            if (!vis[x])
            {
                q.push({x, fr.second + 1});
                vis[x] = true;
            }
        }
    }

    return 0;
}
