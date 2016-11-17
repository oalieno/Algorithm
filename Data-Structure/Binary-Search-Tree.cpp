struct Node{
    int key;
    Node *left,*right;
    Node(){}
    Node(int key):key(key){}
};

Node *root = NULL;

void Insert(int key,Node* now = root){
    if(!root){ root = new Node(key);return; }
    while(now){
        if(key > now->key){
            if(now->right == NULL){ now->right = new Node(key);break; }
            else now = now->right;
        }
        else{
            if(now->left == NULL){ now->left = new Node(key);break; }
            else now = now->left;
        }
    }
}

void Preorder(Node* now = root){
    if(!now) return;
    cout << now->key << " ";
    Preorder(now->left);
    Preorder(now->right);
}


void Inorder(Node* now = root){
    if(!now) return;
    Inorder(now->left);
    cout << now->key << " ";
    Inorder(now->right);
}

void Postorder(Node* now = root){
    if(!now) return;
    Postorder(now->left);
    Postorder(now->right);
    cout << now->key << " ";
}
