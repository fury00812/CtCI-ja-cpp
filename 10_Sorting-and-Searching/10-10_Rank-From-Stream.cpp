#include<iostream>
#include<vector>
using namespace std;

class RankNode {
public:
    int left_size = 0;
    RankNode *left = NULL; // NULLでいいので確保しておくとセグフォが起こらない
    RankNode *right = NULL;
    int data = 0;

    RankNode(int d) {
        data = d;
    }

    //  再帰で要素を挿入; 同時に左の子を数える
    void insert(int d) {
        if (d<=data) {
            if (left != NULL) left->insert(d);
            else left = new RankNode(d);
            left_size++;
        }
        else {
            if (right != NULL) right->insert(d);
            else right = new RankNode(d);
        }
    }

    int getRank(int d) {
        if (d==data) return left_size;
        else if (d < data) {
            if (left==NULL) return -1;
            else return left->getRank(d);
        }
        else {
            if (right==NULL) return -1;
            else {
                int right_rank = right->getRank(d);
                return left_size + 1 + right_rank;
            }
        }
    }

};

RankNode *root;

void track(int number) {
    if (root==NULL) {
        root = new RankNode(number);
    }
    else root->insert(number);
}

int getRankOfNumber(int number) {
    return root->getRank(number);
}

void inorder(RankNode *node) {
    if (node == NULL) return;
    if (node->left != NULL) inorder(node->left);
    cout << " " << node->data;
    if (node->right != NULL) inorder(node->right);
}

void check() {
    cout << "in-order:";
    inorder(root);
    cout << endl;
}

int main() {
    int v[9] = {5,1,4,4,5,9,7,13,3};
    cout << "input:";
    for (int i=0; i<9; ++i) {
        cout << " " << v[i];
        track(v[i]);
    }
    cout << endl;
    check();
    cout << "getRankOfNumber(1) = " << getRankOfNumber(1) << endl;
    cout << "getRankOfNumber(3) = " << getRankOfNumber(3) << endl;
    cout << "getRankOfNumber(4) = " << getRankOfNumber(4) << endl;
}