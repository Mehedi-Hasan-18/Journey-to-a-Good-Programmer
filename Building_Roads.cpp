#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int>adj[N];
bool vis[N];
int parent[N];

void dfs(int src){
    vis[src] = true;
    
    for(auto child : adj[src]){
        if(!vis[child]){
            parent[child] = src;
            dfs(child);
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    
    while(m--){
        int a , b;
        cin>>a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(vis,false,sizeof(vis));
    memset(parent,-1,sizeof(parent));

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
            
        }
    }

    vector<int>ans;
    for(int i=1;i<=n;i++){
        if(parent[i]==-1) ans.push_back(i);
    }
    cout << ans.size()-1<<endl;
    for(int i=1;i<ans.size();i++){
        cout << ans[i-1] <<" "<<ans[i]<<endl;
    }



    return 0;
}
