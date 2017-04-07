// Multiply and Mod ( and prevent overflow )
long long MultiplyMod(long long a,long long b,long long M) {
    if (M <= 1000000000) return a * b % M; 
    long long res = 0;
    while (a > 0) {
        if (a & 1) {
            res += b;
            if (res >= M) res -= M;
        }
        a >>= 1;
        b <<= 1;
        if (b >= M) b -= M;
    }
    return res;
}
