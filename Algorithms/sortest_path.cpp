#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, e;
    cin >> n >> e;
    vector<int> adj[n+1];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int t;
    cin >> t;
    while (t--)
    {
        queue<pair<int, int>> q;
        vector<bool> vis(n, false);
        bool flag = false;
        int src, des;
        cin >> src >> des;

        q.push({src, 0});
        vis[src] = true;

        while (!q.empty())
        {
            auto fr = q.front();
            q.pop();

            if (fr.first == des)
            {
                cout << fr.second << endl;
                flag = true;
                break;
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
        if(!flag) cout << -1 <<endl;
    }

    return 0;
}
