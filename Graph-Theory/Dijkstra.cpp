// one-based

// Time Complexity : O(|E|log|V|)
vector<int> Dijkstra(VPII E[],int N,int S){
    vector<bool> visit(N+1,false);
    vector<int> D(N+1,INF); // D -> Distance
    priority_queue<PII,VPII,greater<PII>> P;
    P.push(mp(0,S));D[S] = 0;
    while(!P.empty()){
        int weight = P.top().ff,now = P.top().ss;P.pop();
        if(visit[now])continue;
        visit[now]=true;
        for(auto i:E[now]){
            int potential = D[now]+i.ff;
            if(!visit[i.ss] && potential < D[i.ss]) P.push(mp(D[i.ss] = potential,i.ss));
        }
    }
    return D;
}
