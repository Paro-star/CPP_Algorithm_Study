//
// Created by duong on 4/28/2026.
//
#include <iostream>

using namespace std;

struct Node {
    int Key;
    int Row;
    int Col;
    Node *Left, *Right;
    Node(int x) : Key(x), Left(nullptr), Right(nullptr) {}
};

bool Add(Node * & Root, int x) {
    if (Root == nullptr) {
        Root = new Node(x);
        return true;
    }

    if (Root->Key == x) return false;

    bool Added = false;
    if (Root->Key < x)
        Added = Add(Root->Right, x);
    else
        Added = Add(Root->Left, x);
    return Added;
}

int GetDigit(int x) {
    if (x == 0) return 1;
    if (x < 0) x = -x;
    int count = 0;
    while (x > 0) {
        count++;
        x /= 10;
    }
    return count;
}

int MaxRow = 0;
int MaxCol = 0;
int MaxDigit = 0;

void Inorder(Node * Root, int Depth) {
    if (Root == nullptr) return;
    Inorder(Root->Left, Depth + 1);

    Root->Col = MaxCol;
    Root->Row = Depth;

    int Digit = GetDigit(Root->Key);
    if (Digit > MaxDigit)
        MaxDigit = Digit;
    if (Depth > MaxRow)
        MaxRow = Depth;

    MaxCol ++;

    Inorder(Root->Right, Depth + 1);
}

void DrawTree(Node * Root, char **Table) {
    if (Root == nullptr) return;
    DrawTree(Root->Left, Table);

    int x = Root->Col * MaxDigit;
    int y = Root->Row;
    int Val = Root->Key;

    char Temp[20];
    int DigitCount = 0;
    if (Val == 0) {
        Temp[DigitCount++] = '0';
    }
    else {
        while (Val > 0) {
            Temp[DigitCount++] = '0' + Val % 10;
            Val /= 10;
        }
    }

    int Zeros = MaxDigit - DigitCount;
    for (int i = 0; i < Zeros; i++) {
        Table[y][x + i] = '0';
    }
    for (int i = 0; i < DigitCount; i++) {
        Table[y][x + i + Zeros] = Temp[DigitCount - 1 - i];
    }

    DrawTree(Root->Right, Table);
}

void DrawDots(Node * Root, char **Table) {
    if (Root == nullptr) return;
    if (Root->Left != nullptr) {
        int Start = (Root->Left->Col + 1) * MaxDigit;
        int End = Root->Col * MaxDigit;
        for (int i = Start; i < End; i++) {
            Table[Root->Row][i] = '.';
        }
        DrawDots(Root->Left, Table);
    }
    if (Root->Right != nullptr) {
        int Start = (Root->Col + 1) * MaxDigit;
        int End = Root->Right->Col * MaxDigit;
        for (int i = Start; i < End; i++) {
            Table[Root->Row][i] = '.';
        }
        DrawDots(Root->Right, Table);
    }
}

int main() {
    int x;
    Node * Root = nullptr;

    while (cin >> x && x != 0) {
        Add(Root, x);
    }

    Inorder(Root, 0);

    int TotalHigh = MaxRow + 1;
    int TotalCol = MaxCol * MaxDigit;

    char **Table = new char*[TotalHigh];
    for (int i = 0; i < TotalHigh; i++) {
        Table[i] = new char[TotalCol + 1];
        for (int j = 0; j < TotalCol; j++) {
            Table[i][j] = ' ';
        }
        Table[i][TotalCol] = '\0';
    }

    DrawTree(Root, Table);
    DrawDots(Root, Table);
    for (int i = 0; i < TotalHigh; i++) {
        cout << Table[i] << endl;
    }

    for (int i = 0; i <TotalHigh; i++) {
        delete[] Table[i];
    }
    delete[] Table;
    return 0;
}