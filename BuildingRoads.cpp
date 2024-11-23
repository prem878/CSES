#include <iostream>
#include <vector>
 
using namespace std;
 
class DisjointSetUnion {
public:
    vector<int> parent;
    vector<int> rank;
 
    DisjointSetUnion(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }
 
    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }
 
    void unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) {
            return;
        }
        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
 
    int count(int n) {
        int fk = 0;
        for (int i = 1; i <= n; ++i) {
            if (parent[i] == i) {
                fk++;
            }
        }
        return fk;
    }
};
 
int main() {
    int n, m;
    cin >> n >> m;
 
    DisjointSetUnion dsu(n);
 
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        dsu.unite(u, v);
    }
    int count=dsu.count(n);
    cout<<count-1<<"\n";
    vector<int> pr;
    for(int i=1;i<=n;++i){
        if(dsu.parent[i]==i){
            pr.push_back(i);
        }
    }
    int sn=pr.size();
    for(int i=0;i<sn-1;i++){
        cout<<pr[i]<<" "<<pr[i+1]<<"\n";
    }
    
    return 0;
}
