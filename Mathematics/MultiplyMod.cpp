// Multiply and Mod ( and prevent overflow )
long long MultiplyMod(long long a,long long b,long long mod) {
    long long res = 0;
    for(a %= mod,b %= mod;b != 0;a <<= 1,b >>= 1,a = a >= mod ? a - mod : a){
        if(b & 1){
            res += a;
            if(res >= mod) res -= mod;
        }
    }
    return res;
}
