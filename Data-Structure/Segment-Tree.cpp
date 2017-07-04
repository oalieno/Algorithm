/* POJ 2777 Partial Code */

struct Node{
    bitset<30> value; // need -1
    int lazy;
    Node *lc,*rc;
    Node():lc(NULL),rc(NULL),lazy(0){}
    void pull(){ value = lc->value | rc->value; }
    void push(){
        if(!lazy) return;
        if(lc){ lc->lazy = lazy;lc->value.reset();lc->value.set(lazy-1); }
        if(rc){ rc->lazy = lazy;rc->value.reset();rc->value.set(lazy-1); }
        lazy = 0;
    }
};

int A[NUM];

Node* build(int L,int R){
    Node *node = new Node();
    if(L == R){
        node->value.reset();node->value.set(A[L]-1);
        return node;
    }
    int mid = (L+R)>>1;
    node->lc = build(L,mid);
    node->rc = build(mid+1,R);
    node->pull();
    return node;
}

void modify(Node *node,int L,int R,int ql,int qr,int d){
    if(R < ql || qr < L)return;
    if(ql <= L && R <= qr){
        node->lazy = d;
        node->value.reset();node->value.set(d-1);
        return;
    }
    node->push();
    int mid = (L+R)>>1;
    modify(node->lc,L,mid,ql,qr,d);
    modify(node->rc,mid+1,R,ql,qr,d);
    node->pull();
}

bitset<30> query(Node* node,int L,int R,int ql,int qr){
    if(R < ql || qr < L) return bitset<30>(0);
    if(ql <= L && R <= qr) return node->value;
    node->push();
    int mid = (L+R)>>1;
    return query(node->lc,L,mid,ql,qr) | query(node->rc,mid+1,R,ql,qr);
}
