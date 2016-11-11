const int MAXCHAR = 10;
const char CHAR = '0';

struct Node{
    int N;
    Node* child[MAXCHAR];
    Node():N(0){ for(int i=0;i<MAXCHAR;i++) child[i] = NULL; }
};

Node* root = new Node;

void word(string text){
    Node* now = root;
    for(int i=0;i<text.size();i++){
        int c = text[i] - CHAR;
        if(now->child[c] == NULL) now->child[c] = new Node;
        now = now->child[c];
    }
    now->N++;
}

void release(Node* now = root){
    for(int i=0;i<MAXCHAR;i++) if(now->child[i]) release(now->child[i]);
    delete now;
}
