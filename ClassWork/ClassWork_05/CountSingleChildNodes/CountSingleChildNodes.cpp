//
// Created by duong on 5/19/2026.
//
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;



//###INSERT CODE HERE -

struct Node {
    int key;
    Node * left, *right;
    Node(int k = 0) : key(k), left(NULL), right(NULL) {}
};

bool AddNodes(Node * & root, int k) {
    if (root == 0) {
        root = new Node(k);
        return true;
    }
    if (root->key == k) return false;
    if (root->key < k) return AddNodes(root->right, k);
    return AddNodes(root->left, k);
}

int CountNodesOneChild(Node * root) {
    if (root == NULL) return 0;
    bool isOneChild = true;
    if (root->left == NULL && root->right == NULL) isOneChild = false;
    if (root->left != NULL && root->right != NULL) isOneChild = false;
    return isOneChild + CountNodesOneChild(root->left) + CountNodesOneChild(root->right);
}

int main() {
    int x;
    Node * root = NULL;
    while (cin >> x && x != 0) {
        AddNodes(root, x);
    }
    cout << CountNodesOneChild(root) << endl;
    return 0;
}
