//
// Created by duong on 4/26/2026.
//
#include <iostream>

#define ll long long
using namespace std;

struct Node {
    int key;
    int size;
    Node *left = 0, *right = 0;
    Node(int x) : key(x) , size(1), left(0), right(0) {}
};


bool add(Node * & root, int x) {
    if (root == 0) {
        root = new Node(x);
        return true;
    }
    if (root->key == x) return false;
    bool added = false;
    if (root->key < x)
        added = add(root->right, x);
    else
        added = add(root->left, x);
    if (added)
        root->size += 1;
    return added;
}


void DUMP(Node * root) {
    if (root == 0) return;
    cout << (ll)root << " "
        << root->key << " "
        << root->size << " "
        << (ll)root->left << " "
        << (ll)root->right << endl;
    DUMP(root->left);
    DUMP(root->right);
}

//In Phai, Giua, Trai
void Print_1(Node * root, int level) {
    if (root == 0) return;
    Print_1(root->right, level + 1);
    for (int i = 0; i < level; i++) {
        cout << "....";
    } cout << root->key << endl;
    Print_1(root->left, level + 1);
}

// In Giua, Trai, Phai
void Print_2(Node * root, int level) {
    if (root == 0) return;
    for (int i = 0; i < level; i++) {
        cout << "....";
    } cout << root->key << endl;
    Print_2(root->left, level + 1);
    Print_2(root->right, level + 1);
}

int main() {
    int x;
    Node * root = 0;

    while (cin >> x && x != 0) {
        add(root, x);
    }

    DUMP(root);
    Print_1(root, 0);
    cout << "\n";
    Print_2(root, 0);
    return 0;
}