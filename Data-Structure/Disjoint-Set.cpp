struct DS{
    vector<int> p;
    void init(int n){ for(int i=0;i<n;i++) p.push_back(i); } // zero-based
    int find(int x){ return x == p[x] ? x : p[x] = find(p[x]); } // Complexity : O(a(N))
    void union_(int x,int y){ p[find(x)] = find(y); } // Complxity : O(a(N))
};
