// Normal Version
int dp[NUM][NUM];

int C(int N,int M){
    if(M < N/2)M = N-M;
    if(M == 0)return 1;
    if(dp[N][M] == -1)dp[N][M] = C(N-1,M)+C(N-1,M-1);
    return dp[N][M];
}

// Mod Version
int factor[NUM], invfactor[NUM];

void initialize(){
    factor[0] = 1; for(int i = 1; i < NUM; i++) factor[i] = i * factor[i-1] % MOD;
    invfactor[0] = 1; for(int i = 1; i < NUM; i++) invfactor[i] = Inverse(i) * invfactor[i-1] % MOD;
}

int C(int N,int M){
    if(N < M) return 0;
    return factor[N] * invfactor[N-M] % MOD * invfactor[M] % MOD;
}
