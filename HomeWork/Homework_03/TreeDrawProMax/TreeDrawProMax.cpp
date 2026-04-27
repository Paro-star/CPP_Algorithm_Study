//
// Created by duong on 4/27/2026.
//
#include <iostream>

using namespace std;

struct Node {
    int key;
    int size;
    Node *left, *right;
    Node(int x) : key(x), size(1), left(0), right(0) {}
};

bool add(Node * & root, int x) {
    if (root == 0){
        root = new Node(x);
        return true;
    }
    if (root->key == x) return false;

    bool added = false;
    if (root->key < x)
        added = add(root->right, x);
    else {
        added = add(root->left, x);
    }

    if (added) root->size += 1;
    return added;
}

void TreeDrawProMax(Node * root, string s, bool isRight, bool isRoot) {
    if (root == 0) return;

    if (root->left != 0) {
        if (isRoot) {
            TreeDrawProMax(root->left, "", false, false);
        }
        else {
            TreeDrawProMax(root->left, s + (isRight ? "|   " : "    "), false, false);
        }
    }

    if (isRoot) {
        cout << root->key << "\n";
    }
    else {
        cout << s << "|---" << root->key << "\n";
    }

    if (root->right != 0) {
        if (isRoot) {
            TreeDrawProMax(root->right, "", true, false);
        }
        else {
            TreeDrawProMax(root->right, s + (isRight ? "    " : "|   "), true, false);
        }
    }
}

int main() {
    int x;
    Node * root = 0;

    while (cin >> x && x != 0) {
        add(root, x);
    }

    TreeDrawProMax(root, "", false, true);
    return 0;
}