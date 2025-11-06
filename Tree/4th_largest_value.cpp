#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    set<int> s;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        s.insert(a);
    
    }
    
    if(s.size()>=4) {
        cout << *next(s.rbegin(), 3) << "\n";
        return 0;
    }
    else if(s.size()==3) {
        cout << *next(s.rbegin(), 2) << "\n";
        return 0;
    }
    else if(s.size()==2) {
        cout << *next(s.rbegin(), 1) << "\n";
        return 0;
    }
    else {
        cout << *s.rbegin() << "\n";
    }
    
    return 0;
}
