#include <bits/stdc++.h>
using namespace std;

char a[1005][1005];
int n, m;
bool vis[1005][1005];
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j) {
    return (i >= 0 || i < n || j >= 0 || j < m);
}
int cnt = 0;
void dfs(int x, int y) {
    vis[x][y] = true;
    
    for (pair<int,int> dir : directions) {
        int newX = x + dir.first;
        int newY = y + dir.second;

        if (valid(newX, newY) && !vis[newX][newY] && a[newX][newY]=='.'){
            cnt ++;
            dfs(newX, newY);
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) 
        {
            cin >> a[i][j];
        }
    }
    memset(vis, false, sizeof(vis));
    
    int apartment_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) 
        {
            if (a[i][j] == '.' && !vis[i][j]) {
                apartment_count++;
                cnt = 1;
                dfs(i, j);
                cout <<cnt <<endl;
            }
        }
    }

    cout << apartment_count <<" " <<cnt << endl;

    return 0;
}
