#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int par[N];
int group_size[N];
int level[N];

void dsu_initialize(int n){
    for(int i=0;i<n;i++){
        par[i] = -1;
        group_size[i] = 1;
        level[i] = 0;
    }
}

int dsu_find(int node){
    if(par[node] == -1) return node;
    return par[node] = dsu_find(par[node]);
}

void dsu_union_by_size(int node1,int node2){
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);

    if(leaderA != leaderB){
        if(group_size[leaderA] > group_size[leaderB]){
            par[leaderB] = leaderA;
            group_size[leaderA] += group_size[leaderB];
        }else{
            par[leaderA] = leaderB;
            group_size[leaderB] += group_size[leaderA];
        }
    }
}

void dsu_union_by_rank(int node1,int node2){
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);

    if(leaderA != leaderB){
        if(level[leaderA] > level[leaderB]){
            par[leaderB] = leaderA;
        }
        else if(level[leaderA] < level[leaderB]){
            par[leaderA] = leaderB;
        }
        else{
            par[leaderA] = leaderB;
            level[leaderB]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    dsu_initialize(5);
    dsu_union_by_size(1,2);
    dsu_union_by_size(2,3);
    dsu_union_by_size(5,4);
    dsu_union_by_size(6,5);

    cout << dsu_find(3) << endl; 
    cout << dsu_find(6) << endl; 

    return 0;
}
