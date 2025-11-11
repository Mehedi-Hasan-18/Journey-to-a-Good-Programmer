#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
class EDGE
{
public:
    ll u;
    ll v;
    ll w;
    EDGE(ll u, ll v, ll w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, e;
    cin >> n >> e;

    vector<EDGE> edgelist;

    while (e--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        edgelist.push_back(EDGE(a, b, c));
    }

    vector<ll> dis(n + 1, LLONG_MAX);
    ll src;
    cin >> src;
    dis[src] = 0;
    bool cycle = false;
    for (ll i = 0; i < n; i++)
    {
        for (EDGE ed : edgelist)
        {
            if (dis[ed.u] != LLONG_MAX && dis[ed.u] + ed.w < dis[ed.v])
            {
                dis[ed.v] = dis[ed.u] + ed.w;
            }
        }
    }
    for (EDGE ed : edgelist)
    {
        if (dis[ed.u] != LLONG_MAX && dis[ed.u] + ed.w < dis[ed.v])
        {
            cycle = true;
            break;
        }
    }
    ll t;
    cin >> t;

    if (cycle)
        cout << "Negative Cycle Detected\n";
    else
    {
        while (t--)
        {
            ll des;
            cin >> des;

            if (dis[des] == LLONG_MAX)
                cout << "Not Possible\n";
            else
                cout << dis[des] << endl;
        }
    }
    return 0;
}
