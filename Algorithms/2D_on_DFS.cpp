#include <bits/stdc++.h>
using namespace std;


int n, m;
vector<pair<int, int>> d{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<vector<int>> v;
vector<vector<bool>> vis;

bool valid(int i, int j)
{
    if (i >= n || i < 0 || j >= m || j < 0)
        return false;
    else
        return true;
}
void dfs(int si, int sj)
{
    cout << v[si][sj] << " ";
    vis[si][sj] = true;

    for (pair<int, int> p : d)
    {
        int ci = si+p.first;
        int cj = sj+p.second;

        if(valid(ci,cj) && !vis[ci][cj]){
            dfs(ci,cj);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    v.assign(n,vector<int>(m));
    vis.assign(n,vector<bool>(m,false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    int si,sj;
    cin >> si>>sj;
    dfs(si,sj);

    return 0;
}
