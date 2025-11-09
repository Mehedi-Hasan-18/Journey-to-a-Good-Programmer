#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int inf = INT_MAX;
vector<pair<int, int>> adj[N];
int dis[N];

class cmp
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

void dijkstra(int s)
{
    priority_queue<pair<int, int>,vector<pair<int,int>>,cmp> q;
    q.push({s, 0});
    dis[s] = 0;
    while (!q.empty())
    {
        pair<int, int> fr = q.top();
        q.pop();

        for (auto child : adj[fr.first])
        {
            
            if (dis[child.first] > dis[fr.first] + child.second)
            {
                dis[child.first] = dis[fr.first] + child.second;
                q.push({child.first,dis[child.first]});
            }
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
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    fill(dis, dis + N, inf);

    dijkstra(0);

    for(int i=0;i<n;i++){
        cout << "Distance from 0 to " << i << " is " << dis[i] << "\n";
    }

    return 0;
}
