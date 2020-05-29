#include<iostream>
using namespace std;

struct Node {
    int key;
    Node *parent; // 親ノードを保持
    Node *left;
    Node *right;
};

//Node *root = new Node;
Node *root;

void insert(int key) {
    Node *i, *j, *n;

    n = new Node; // 追加したいノード
    n->key = key;
    n->left = NULL;
    n->right = NULL;
    j = root;
    while(j != NULL) { //　挿入位置まで辿る 
        i = j; // iはjの親
        if (n->key < j->key) j = j->left;
        else j = j->right;
    }
    n->parent = i;
    if (i == NULL) root = n; // 木が存在しない
    else if (n->key < i->key) i->left = n;
    else i->right = n;
}

Node *given;
int cnt=0;
int n;

void inorder(Node *node) {
    if (node == NULL) return;
    if (node->left != NULL) inorder(node->left);
    cnt++;
    if (cnt==n) given = node;
    if (node->right != NULL) inorder(node->right);
}

int leftMostChild(Node *n) {
    while (n->left != NULL) {
        n = n->left;
    }
    return n->key;
}

void ans(int now) {
    n=now; cnt=0; inorder(root);
    printf("Next node after %d: ", given->key);
    if (given->right != NULL) {
        cout << leftMostChild(given->right);
    }
    else {
        Node *c = given;
        Node *p = c->parent;
        while (p != NULL && p->left != c) {
            c = p;
            p = c->parent;
        }
        if (p!=NULL) cout << p->key;
        else cout << "NULL";
    }
    cout << endl;
}

int main() {
    // (1) 二分探索木 (深さ3) の作成
    int v[7] = {4,2,3,1,6,7,5};
    for (int i=0; i<7; ++i) {
        insert(v[i]);
    }

    // (2) 問題 (givenの"次"のノードを探す)
    ans(1);
    ans(3);
    ans(4);
    ans(7);
    return 0;
}