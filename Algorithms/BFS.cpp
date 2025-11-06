#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, e;
    cin >> n >> e;
    vector<int> adj[n];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int src;
    cin >> src;

    queue<pair<int, int>> q;
    vector<bool> visit(n, false);
    vector<int> parent(n, -1);
    // int level[n];
    // memset(level, -1, sizeof(level));

    q.push({src, 0});
    // level[src] = 0;
    visit[src] = true;

    while (!q.empty())
    {
        pair<int, int> fr = q.front();
        q.pop();

        cout << fr.first << " " << " at level " << fr.second << "\n";

        for (int x : adj[fr.first])
        {
            if (!visit[x])
            {
                q.push({x, fr.second + 1});
                parent[x] = fr.first;
                // level[x] = level[fr.first] + 1;
                visit[x] = true;
            }
        }
    }

    int val;
    cin >> val;
    while(val != -1){
        cout <<val<<" ";
        val= parent[val];
    }
    

    return 0;
}
