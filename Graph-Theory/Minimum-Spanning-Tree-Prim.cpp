// Time Complexity : O(|V|^2)
void MinimumSpanningTreePrim(int V,vector<pair<int,int>> E[]){
    bool visit[V+1];for(int i=0;i<V+1;i++) visit[i] = false;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> PQ;
    PQ.push(make_pair(0,1));
    while(!PQ.empty()){
        auto now = PQ.top();PQ.pop();
        if(visit[now.second]) continue;
        visit[now.second] = true;
        // do something with now.first
        for(auto i:E[now.second]){
            if(!visit[i.second]) PQ.push(mp(i.first,i.second));
        }
    }
}
