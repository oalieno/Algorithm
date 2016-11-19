struct Node{
    int key;
    Node *parent,*left,*right;
    Node(){}
    Node(int key):key(key),parent(NULL),left(NULL),right(NULL){}
};

Node *root = NULL;

Node* Minimum(Node* now = root){
    while(now->left)now = now->left;
    return now;
}

Node* Maximum(Node* now = root){
    while(now->right)now = now->right;
    return now;
}

Node* Successor(Node* now){
    if(now->right)return Minimum(now->right);
    Node *prev = now->parent;
    while(prev != NULL && now == prev->right){
        now = prev;
        prev = prev->parent;
    }
    return prev;
}

Node* Predecessor(Node* now){
    if(now->left)return Maximum(now->left);
    Node *prev = now->parent;
    while(prev != NULL && now == prev->left){
        now = prev;
        prev = prev->parent;
    }
    return prev;
}

void Insert(int key){
    Node *now = root,*node = new Node(key);
    if(root == NULL){ root = node;return; }
    while(now){
        if(key < now->key){
            if(now->left == NULL){
                now->left = node;
                now->left->parent = now;
                break;
            }
            else now = now->left;
        }
        else{
            if(now->right == NULL){
                now->right = node;
                now->right->parent = now;
                break;
            }
            else now = now->right;
        }
    }
}

void Transplant(Node* A,Node* B){
    if(A->parent == NULL)root = B;
    else if(A == A->parent->left)A->parent->left = B;
    else A->parent->right = A;
    if(B)B->parent = A->parent;
}

void Delete(Node* now){
    if(now->left == NULL)Transplant(now,now->right);
    else if(now->right == NULL)Transplant(now,now->left);
    else{
        Node* small = Minimum();
        Transplant(small,small->right);
        small->right = now->right;
        small->right->parent = small;
        Transplant(now,small);
        small->left = now->left;
        small->left->parent = small;
    }
    delete now;
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
