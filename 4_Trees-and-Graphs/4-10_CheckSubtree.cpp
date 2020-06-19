#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;
};

Node *newNode(int x)
{
    Node *n;
    n = new Node;
    n->key = x;
    n->left = NULL;
    n->right = NULL;
    return n;
}

string str1 = "";
string str2 = "";

void getOrderString(Node *node, string &s) {
    if (node == NULL) {
        s = s+"X";
        return;
    }
    else {
        s = s+to_string(node->key);
        getOrderString(node->left, s);
        getOrderString(node->right, s);
    }
}

bool containsTree(Node *t1, Node *t2) {
    getOrderString(t1, str1);
    getOrderString(t2, str2);
    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    auto pos = str1.find(str2);
    if (pos==string::npos) return false;
    return true; 
}

int main() {
    Node *T1, *T2;
    T1 = new Node;
    T1 = newNode(1);
    T1->left = newNode(2);
    T1->left->left = newNode(4);
    T1->right = newNode(3);

    T2 = new Node;
    T2 = newNode(2);
    T2->left = newNode(4); 
  
    if (containsTree(T1, T2)) cout << "Yay!! T2 is a subtree of T1!!\n";
    else cout << "Oops. T2 is not a subtree of T1.\n";
}