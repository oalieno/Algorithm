struct Treap{
    int pri, key, val, diff;
    Treap *l, *r;
    Treap(){}
    Treap(int key):l(NULL),r(NULL),pri(rand()),key(key){}
};

/*
condition : a's keys < b's keys
return : root
*/
Treap* merge(Treap *a, Treap *b){
    if(!a || !b) return a ? a : b;
    if(a->pri > b->pri){
        a->r = merge(a->r,b);
        return a;
    } else {
        b->l = merge(b->l,a);
        return b;
    }
}

/*
a's keys <= k
b's keys >  k
*/
void split(Treap *t, int k, Treap *&a, Treap *&b){
    if(!t) a = b = NULL;
    else if(t->key <= k){
        a = t;
        split(t->r, k, a->r, b);
    } else {
        b = t;
        split(t->l, k, a, b->l);
    }
}

Treap* insert(Treap *t, int k){
    Treap *a, *b;
    split(t,k,a,b);
    return merge(merge(a,new Treap(k)),b);
}

Treap* remove(Treap *t, int k){
    Treap *a, *b, *c;
    split(t,k-1,a,b);
    split(b,k,b,c);
    return merge(a,c);
}
