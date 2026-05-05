//
// Created by duong on 5/5/2026.
//
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
[
]
###End banned keyword*/
#include <iostream>

using namespace std;

struct Hocsinh{
    string Hodem, Ten;
    bool Gioitinh;
    int Ngay, Thang, Nam;
    double Toan, Van, Ly, Hoa, Anh, Sinh;
};

void InputElement(Hocsinh &x) {
    getline(cin>>ws, x.Hodem);
    getline(cin>>ws, x.Ten);
    cin >> x.Gioitinh;
    cin >> x.Ngay >> x.Thang >> x.Nam;
    cin >> x.Toan >> x.Van >> x.Ly >> x.Hoa >> x.Anh >> x.Sinh;
}

void OutputElement(Hocsinh hs) {
    cout << hs.Hodem
            << ' ' << hs.Ten
            << '\t' << hs.Gioitinh
            << '\t' << hs.Ngay
            << '/' << hs.Thang
            << '/' << hs.Nam
            << '\t' << hs.Toan
            << '\t' << hs.Van
            << '\t' << hs.Ly
            << '\t' << hs.Hoa
            << '\t' << hs.Anh
            << '\t' << hs.Sinh << endl;
}

struct TNode {
    Hocsinh data;
    TNode * left, * right;
};

typedef TNode * TREE;

void CreateTree(TREE &r) {
    r = NULL;
}

TNode * CreateTNode(Hocsinh x) {
    TNode * p = new TNode;
    if (p == NULL) exit(1);
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}


bool Add(TNode * & root, Hocsinh x) {
    if (root == nullptr) {
        root = CreateTNode(x);
        return true;
    }
    if ((root->data.Ten == x.Ten) && (root->data.Hodem == x.Hodem)) return false;
    // so sanh theo ten
    if (root->data.Ten < x.Ten) return Add(root->right, x);
    else if (root->data.Ten == x.Ten) {
        // ten giong nhau thi so sanh theo ho dem
        if (root->data.Hodem < x.Hodem) {
            return Add(root->right, x);
        }
        return Add(root->left, x);
    }
    return Add(root->left, x);
}

void PrintTree(TNode * root) {
    if (root == nullptr) return;
    PrintTree(root->left);
    OutputElement(root->data);
    PrintTree(root->right);
}

int main() {
    int n;
    cin >> n;
    TNode * root;
    CreateTree(root);
    for (int i = 0; i < n; i++) {
        Hocsinh x;
        InputElement(x);
        Add(root, x);
    }
    PrintTree(root);
}

