#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,e;
    cin >> n >> e;
    // Adjacency Matrix Representation
    int matrix[n][n];
    for(int i=0; i<n; i++) {
        int a,b;
        cin >> a>>b;
        matrix[a][b] = 1;
        matrix[b][a] = 1;
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    // Adjacency List Representation
    vector<int> adj[n];
    while(e--){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        for(int x : adj[i]){
            cout << x <<" ";
        }
        cout << endl;
    }
    // Edge List Representation
    vector<pair<int,int>>v;
    while(e--){
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }

    for(pair<int,int> x : v){
        cout << x.first <<" "<<x.second<<endl;
    }



    return 0;
}
