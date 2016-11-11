int E[V+1][V+1],SP[V+1][V+1];

// Complexity : O(V^3)
void FloydWarshall(int V){
    // one-based
    for(int i=1;i<=V;i++) for(int j=1;j<=V;j++) SP[i][j] = E[i][j];
    for(int k=1;k<=V;k++) for(int i=1;i<=V;i++) for(int j=1;j<=V;j++) SP[i][j] = min(SP[i][j],SP[i][k]+SP[k][j]);
}
