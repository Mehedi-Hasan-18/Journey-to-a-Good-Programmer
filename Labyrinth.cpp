#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
bool vis[N][N];
char arr[N][N];
bool flag;
pair<int, int> par[N][N];
vector<pair<int, int>> dis = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m;

bool valid(int i, int j)
{
    if (i >= n || i < 0 || j >= m || j < 0)
        return false;
    else
        return true;
}

vector<char> ans;

void bfs(int si, int sj, int di, int dj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    par[si][sj] = {-1, -1};

    while (!q.empty())
    {
        auto parent = q.front();
        q.pop();
        int a = parent.first;
        int b = parent.second;

        for (auto x : dis)
        {
            int ci = a + x.first;
            int cj = b + x.second;
            if (ci == di && cj == dj)
            {
                flag = true;
            }

            if (valid(ci, cj) && !vis[ci][cj] && (arr[ci][cj] == '.' || arr[ci][cj] == 'B'))
            {
                vis[ci][cj] = true;
                par[ci][cj] = {a, b};
                q.push({ci, cj});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    int si, sj;
    int di, dj;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'A')
            {
                si = i;
                sj = j;
            }
            if (arr[i][j] == 'B')
            {
                di = i;
                dj = j;
            }
        }
    }

    flag = false;
    memset(vis, false, sizeof(vis));
    bfs(si, sj, di, dj);
    if (flag)
    {
        cout << "YES\n";
        pair<int, int> p = {di, dj};
        vector<pair<int, int>> path;
        while (!(p.first == si && p.second == sj))
        {
            path.push_back(p);
            p = par[p.first][p.second];
        }
        path.push_back({si, sj});

        reverse(path.begin(), path.end());

        string ans = "";
        for (int i = 1; i < path.size(); i++)
        {
            if (path[i - 1].first == path[i].first)
            {
                if (path[i - 1].second + 1 == path[i].second)
                    ans += "R";
                else
                    ans += "L";
            }
            else
            {
                if (path[i - 1].first + 1 == path[i].first)
                    ans += "D";
                else
                    ans += "U";
            }
        }
        cout << ans.size()<<endl;
        cout << ans << endl;
    }
    else
        cout << "NO\n";

    return 0;
}
