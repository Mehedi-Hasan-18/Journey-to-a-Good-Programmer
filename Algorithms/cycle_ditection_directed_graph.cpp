#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> adj[N];
bool vis[N];
bool pathVisit[N];
int parent[N];
bool ans;

void dfs(int s){
    vis[s] = true;
    pathVisit[s] = true;
    for(int x : adj[s]){
        if(pathVisit[x]){
            ans = true;
        }
        if(!vis[x]){
            dfs(x);
        }
        
    }
    pathVisit[s] = false;
    
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

    }
    memset(vis,false,sizeof(vis));
    memset(pathVisit,false,sizeof(pathVisit));
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
