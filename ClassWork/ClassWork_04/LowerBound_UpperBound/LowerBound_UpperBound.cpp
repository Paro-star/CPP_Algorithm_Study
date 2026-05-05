//
// Created by duong on 5/5/2026.
//
#include <iostream>

using namespace std;

struct Node {
    int key;
    Node *left, *right;
    Node (int key = 0) : key(key), left(nullptr), right(nullptr) {}
};

bool Add(Node * & root, int x) {
    if (root == nullptr) {
        root = new Node(x);
        return true;
    }
    if (root->key == x) return false;
    if (root->key < x) return Add(root->right, x);
    return Add(root->left, x);
}

Node * LowerBound(Node * root, int x) {
    Node * trav = root;
    Node * res = nullptr;
    while (trav != nullptr) {
        if (trav->key < x) {
            res = trav;
            trav = trav->right;
        }
        else {
            trav = trav->left;
        }
    }
    return res;
}

Node * UpperBound(Node * root, int x) {
    Node * trav = root;
    Node * res = nullptr;
    while (trav != nullptr) {
        if (trav->key > x) {
            res = trav;
            trav = trav->left;
        }
        else {
            trav = trav->right;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int Choice, x;
    Node * root = nullptr;
    while (cin >> Choice && Choice != 0) {
        cin >> x;
        if (Choice == 1) {
            // add
            Add(root, x);
        }
        else if (Choice == 2) {
            // tim lowerbound
            Node * p = LowerBound(root, x);
            if (p == nullptr) {
                cout << "NULL\n";
            }
            else {
                cout << p->key << "\n";
            }
        }
        else if (Choice == 3) {
            // tim upperboud
            Node * p = UpperBound(root, x);
            if (p == nullptr) {
                cout << "NULL\n";
            }
            else {
                cout << p->key << "\n";
            }
        }
    }
    return 0;
}