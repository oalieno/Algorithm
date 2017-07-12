/*
can   : range query min/max
can't : update, insert, delete
*/

const int N = 1000000;
const int logN = ceil(log(N));

int value[N];
int t[logN][N]; // t[i][j]儲存區間[j, j+2ⁱ-1]的最小值的索引值

void construct(){
    // 寬度為1的區間最小值
    for (int i=0; i<N; ++i) t[0][i] = value[i];
    // index : for (int i=0; i<N; ++i) t[0][i] = i;

    // 寬度為2、4、8、...的區間最小值
    for (int i=1; (1<<i)<=N; ++i) for (int j=0; j+(1<<i)<=N; ++j){
        int &L = t[i-1][j];
        int &R = t[i-1][j+(1<<(i-1))];
        t[i][j] = min(L,R);
        // index : t[i][j] = (value[L] <= value[R] ? L : R);
    }
}

int query(int a, int b){
    int p = 31 - __builtin_clz(abs(b - a) + 1);  // evil O(1)

    int &L = t[p][a];
    int &R = t[p][b-(1<<p)+1];
    return min(L,R);
    // index : return value[L] <= value[R] ? L : R;
}
