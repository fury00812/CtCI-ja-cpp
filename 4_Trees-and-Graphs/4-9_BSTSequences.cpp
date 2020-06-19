#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

struct Node {
    int key;
    Node *parent;
    Node *left;
    Node *right;
};

//Node *root = new Node;
Node *root;

//vector <Node> Nodes; // 順列生成用
map <int, int> families; // 検索用 <子, 親>
vector <int> children;

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
    if (i == NULL) {
        root = n; // 木が存在しない
        families[n->key] = 0;
    }
    else {
        if (n->key < i->key) i->left = n;
        else i->right = n;
        families[n->key] = i->key;
    }
    children.push_back(n->key);
    //Nodes.push_back(*n);
    
}

void ans() {
//    for (int i=0; i<families.size(); i++) {
//        cout << families.at(i).first;
//        cout << families.at(i).second << endl;
//    }
    bool is_ok;
    sort(children.begin(), children.end());
    do {
        vector<int> tmp;
        is_ok = true;
        for (int i=0; i<children.size(); i++) {
            tmp.push_back(children.at(i));
            int p = families[children.at(i)];
            if (p!=0 && find(tmp.begin(), tmp.end(), p)==tmp.end()) {
                is_ok = false;
                break;
            }
        }
        if(is_ok) {
            cout << "[";
            for (int j=0; j<tmp.size(); j++) {
                cout << tmp.at(j) << " ";
            }
            cout << "]\n";
        }
    } while(next_permutation(children.begin(), children.end()));
}


int main() {
    // case1: 深さ2の平衡木
    //int v[3] = {2,3,1};
    //for (int i=0; i<3; ++i) {
    //    insert(v[i]);
    //}
    //ans(); 
    
    // case2: 深さ3の平衡木
    int v[7] = {4,2,3,1,6,7,5};
    for (int i=0; i<7; ++i) {
        insert(v[i]);
    }
    ans();
}
