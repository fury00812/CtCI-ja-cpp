#include<iostream>
using namespace std;

struct Node {
    int key;
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

    if (i == NULL) root = n; // 木が存在しない
    else if (n->key < i->key) i->left = n;
    else i->right = n;
}

void inorder(Node *node) {
    if (node == NULL) return;
    if (node->left != NULL) inorder(node->left);
    cout << " " << node->key;
    if (node->right != NULL) inorder(node->right);
}

int height(Node *root) {
    if (root == NULL) return 0;
    else {
        int l_height = height(root->left);
        int r_height = height(root->right);
        return max(l_height, r_height)+1;
    }
}

void printLinks(Node *root, int depth) {
    if (depth == 1) {
        cout << root->key << "->";
    }
    else if (depth>1) {
        printLinks(root->left, depth-1);
        printLinks(root->right, depth-1);
    }
}

void ans(Node *root) {
    int h = height(root);
    for (int i=1; i<=h; i++) {
        cout << "Depth " << i << ": head->";
        printLinks(root, i);
        cout << "tail \n";
    }
}


int main() {
    // (1) 二分探索木 (深さ3) の作成
    int v[7] = {4,2,3,1,6,7,5};
    for (int i=0; i<7; ++i) {
        insert(v[i]);
    }
    cout << "in-order:";
    inorder(root);
    cout << endl;

    // (2) 問題 (深さ毎の連結リスト作成)
    ans(root);
    return 0;
}
