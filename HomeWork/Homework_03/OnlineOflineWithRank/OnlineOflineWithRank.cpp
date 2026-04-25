//
// Created by duong on 4/25/2026.
//
#include <iostream>

using namespace std;

struct Node {
    int key;
    int smaller;
    Node *left, *right;
    Node(int k) : key(k), smaller(0), left(0), right(0) {}
};

bool add(Node * & root, int x) {
    if (root == 0) {
        root = new Node (x);
        return true;
    }
    // x = root->key : khong them;
    if (root->key == x) return false;
    // x > root->key : them vao ben phai
    if (root->key < x) return add(root->right, x);
    // x < root->key : them vao ben trai
    auto kq = add(root->left, x);
    if (kq) root->smaller += 1;
    return kq;
}

int index(Node * root, int x) {
    if (root == 0) return -1;
    if (root->key == x) return root->smaller;
    if (x < root->key) return index (root->left, x);

    int res = index (root->right, x);
    return (res == -1) ? -1 : root->smaller + 1 + res;
}

bool remove(Node * & root, int x) {
    // rong thi khoi xoa;
    if (root == 0) return false;
    // xoa ben phai thi khong can cap nhat lai;
    if (root->key < x) return remove (root->right, x);
    //Xoa ben trai thi phai cap nhat lai smaller;
    if (x < root->key) {
        bool temp = remove (root->left, x);
        if (temp) root->smaller -= 1;
        return temp;
    }
    // root->key == x
    if (root->left == 0 && root->right == 0) {
        auto temp = root;
        root = 0; // bao cho cha no biet con m dang xuat roi
        delete temp; // khu thang con no
        return true;
    }
    //co con trais
    else if (root->right == 0) {
        auto temp = root->left;
        delete root;
        root = temp;
        return true;
    }
    else if (root->left == 0) {
        auto temp = root->right;
        delete root;
        root =temp;
        return true;
    } // tim thang con lon nhat trong nhung thang con ben trai
    else {
        auto temp = root->left;
        while (temp->right != 0) temp = temp->right;
        root->key = temp->key;
        remove (root->left, temp->key);
        root->smaller -= 1;
        return true;
    }
}

void DUMP(Node * root) {
    if (root == 0) return;
    cout << root->key << " "
        << root->smaller << " "
        << root->left << " "
        << root->right << " \n";
    DUMP(root->left);
    DUMP(root->right);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    Node * root = 0;
    while (cin >> a && a != 0) {
        cin >> b;
        if (a == 1) {
            add(root, b);
        }
        else if (a == 2) {
            cout << index(root, b) + 1 << "\n";
        }
        else if (a == 3) {
            remove (root, b);
        }
    }
    return 0;
}