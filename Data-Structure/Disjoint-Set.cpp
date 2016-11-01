struct DisjointSet{
    int p[100];
    void Init(int n){ for(int i=0;i<n;i++) p[i] = i; } // zero-based
    int Find(int x){ return x == p[x] ? x : p[x] = Find(p[x]); }
    void Union(int x,int y){ p[Find(x)] = Find(y); }
};
