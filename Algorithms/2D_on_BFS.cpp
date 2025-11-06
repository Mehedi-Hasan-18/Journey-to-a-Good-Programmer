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
void bfs(int si, int sj)
{
    queue<pair<pair<int,int>,int>>q;
    q.push({{si,sj},0});
    vis[si][sj] = true;
    while(!q.empty()){
        pair<pair<int,int>,int> fr = q.front();
        q.pop();

        pair<int,int> position = fr.first;
        int ci = position.first;
        int cj = position.second;
        int level = fr.second;

        cout << v[ci][cj] << " " <<level <<endl;

        for(auto x : d){
            if(valid(ci+x.first,cj+x.second) && !vis[ci+x.first][cj+x.second]){
                q.push({{ci+x.first,cj+x.second},level+1});
                vis[ci+x.first][cj+x.second] = true;
            }
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
    bfs(si,sj);

    return 0;
}
