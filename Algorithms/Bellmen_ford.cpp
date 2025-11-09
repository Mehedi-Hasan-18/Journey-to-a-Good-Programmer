#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int u, v, weight;
    Edge(int u, int v, int weight)
    {
        this->u = u;
        this->v = v;
        this->weight = weight;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, e;
    cin >> n >> e;
    vector<Edge> edges;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (auto ed : edges)
        {
            if (dist[ed.u] != INT_MAX && dist[ed.u] + ed.weight < dist[ed.v])
            {
                dist[ed.v] = dist[ed.u] + ed.weight;
            }
        }
    }
    bool cycle = false;
    for (auto ed : edges)
    {
        if (dist[ed.u] != INT_MAX && dist[ed.u] + ed.weight < dist[ed.v])
        {
            cycle = true;
            break;
        }
    }

    if (cycle)
        cout << "Cycle Found\n";
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << dist[i] << " ";
        }
    }

    return 0;
}
