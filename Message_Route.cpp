#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
bool vis[N];
int parent[N];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while (!q.empty())
    {
        int fr = q.front();
        q.pop();

        for (int x : adj[fr])
        {
            if (!vis[x])
            {
                vis[x] = true;
                parent[x] = fr;
                q.push(x);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));

    bfs(1);

    if (parent[n] == -1)
        cout << "IMPOSSIBLE\n";
    else
    {
        vector<int> ans;
        int x = n;
        while (parent[x] != -1)
        {
            ans.push_back(x);
            x = parent[x];
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (auto val : ans)
        {
            cout << val << " ";
        }
    }

    return 0;
}
