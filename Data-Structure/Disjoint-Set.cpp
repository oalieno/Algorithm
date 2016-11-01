struct DisjointSet{
    int p[100],s[100];
    void Init(int n){
        for(int i=0;i<n;i++){
            p[i] = i;
            s[i] = 1;
        }
    }
    int Find(int x){ return x == p[x] ? x : p[x] = Find(p[x]); }
    void Union(int x,int y){
        int xx = Find(x),yy = Find(y);
        if(xx == yy)return;
        s[yy] += s[xx];
        p[xx] = yy;
    }
};
