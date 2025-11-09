#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> adj[N];
bool vis[N];
int parent[N];
bool ans;


void bfs(int s){
    queue<int>q;
    q.push(s);
    vis[s] = true;
    while(!q.empty()){
        int fr = q.front();
        q.pop();

        for(int x: adj[fr]){
            if(vis[x] && parent[fr] != x){
                ans = true;
            }
            if(!vis[x]){
                q.push(x);
                vis[x] = true;
                parent[x] = fr;
            }
        }
    }
}

void dfs(int s){
    vis[s] = true;
    for(int x : adj[s]){
        if(vis[x] && parent[s] != x){
            ans = true;
        }
        if(!vis[x]){
            parent[x] = s;
            dfs(x);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,e;
    cin >> n>>e;
    while(e--){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);

    }
    memset(vis,false,sizeof(vis));
    memset(parent,-1,sizeof(parent));
    ans = false;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    if(ans) cout <<"Cycle Found\n";
    else cout <<"Not Found\n";

    return 0;
}
