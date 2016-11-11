// Time Complexity : O(ElogE)
struct Edge{ int x,y,weight; };
bool operator<(const Edge& A,const Edge& B){ return A.weight < B.weight; }

void MinimumSpanningTreeKruskal(int V,vector<Edge> E){
    DisjointSet DS;DS.Init(V);
    sort(E.begin(),E.end());
    for(int i=0;i<E.size();i++){
        if(DS.Find(E[i].x) == DS.Find(E[i].y)) continue;
        DS.Union(E[i].x,E[i].y);
        // do something with E[i].weight
    }
}
