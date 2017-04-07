int BinaryGCD(int x,int y){
    int shift = 0;
    while(x != y){
        if(x < y)swap(x,y);
        bool xx = (x&1);
        bool yy = (y&1);
        if(xx && yy) x = (x-y)>>1;
        else if(!xx && yy) x >>= 1;
        else if(xx && !yy) y >>= 1;
        else { x >>= 1;y >>= 1;shift++; }
    }
    return x<<shift;
}
