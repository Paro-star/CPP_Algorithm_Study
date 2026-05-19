//
// Created by duong on 5/19/2026.
//
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/
#include <iostream>

using namespace std;

struct Node{
    int val;
    Node *left, *right;
};

void add(Node* &root, int x){
    /*
        Hàm thêm một số vào cây
        Hàm này đã được viết đầy đủ và đảm bảo đúng
        Sinh viên không cần phải viết hàm này
    */
    if (root == NULL){
        root = new Node;
        root->val = x;
        root->left = root->right= NULL;
    } else {
        if (x < root->val) add(root->left, x);
        else if (x > root->val) add(root->right, x);
    }
}

//###INSERT CODE HERE -
pair<int, int> balance(Node * root) {
    if (root == NULL) return {0, 0};
    auto l = balance(root->left), r = balance(root->right);
    return {
        (abs(l.second - r.second) > 1) + l.first + r.first
        , max(l.second, r.second) + 1
    };
}

int unbalance(Node * root) {
    return balance(root).first;
}

int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    Node *root = NULL;

    int x;
    while (cin >> x){
        add(root, x);
    }

    cout << "So node bi mat can bang la " << unbalance(root);
    return 0;
}
