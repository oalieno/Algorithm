struct DisjointSet{
    vector<int> p;
    void Init(int n){ for(int i=0;i<n;i++) p.push_back(i); } // zero-based
    int Find(int x){ return x == p[x] ? x : p[x] = Find(p[x]); } // Complexity : O(a(N))
    void Union(int x,int y){ p[Find(x)] = Find(y); } // Complxity : O(a(N))
};
