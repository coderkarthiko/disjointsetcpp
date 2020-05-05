#include <bits/stdc++.h>
using namespace std;

void init(vector<int>& v) {
    for(int i = 0; i < v.size(); i ++) {
        v[i] = i;
    }
}

int root(vector<int>& v, int x) {
    while(v[x] != x) {
        x = v[v[x]];
    }
    return x;
}

void join(vector<int>& v, int a, int b) {
    v[root(v, v[a])] = root(v, v[b]);
}

void ret(vector<int>& v) {
    for(int i = 0; i < v.size(); i ++) {
        v[i] = root(v, v[i]);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    init(v);
    for(int i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        join(v, a, b);
    }
    ret(v);
    for(auto i: v) {
        cout << i << " ";
    }
}
