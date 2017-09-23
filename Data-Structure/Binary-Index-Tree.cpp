/*
can   update, range query sum
can't insert, delete
*/

struct BIT{
    vector<int> A;
    inline int lower_bit(int x){ return x & -x; }
    int sum(int x){
        int s = 0;
        while(x > 0){
            s += A[x];
            x -= lower_bit(x);
        }
        return s;
    }

    void add(int x,int d){
        while(x <= A.size()){
            A[x] += d;
            x += lower_bit(x);
        }
    }

    int query(int a,int b){
        if(a > b) swap(a,b);
        return sum(b)-sum(a-1);
    }
};

