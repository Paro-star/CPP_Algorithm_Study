#include <iostream>

using namespace std;

struct node
{
    int value;
    node *left = 0, *right = 0;
    int size;
};

int get_size(node *obj)
{
    return (obj == 0) ? 0 : obj->size;
}

bool add(node * &root, int x)
{
    if(root == 0)
    {
        root = new node{x, 0, 0, 1};
        return true;
    }
    
    if(root->value == x)
        return false;
    
    bool added = false;

    if(root->value < x)
        added = add(root->right, x);
    else
        added = add(root->left,x );
    
    if(added)
        root->size++;
    return added;
}

int find(node * root, int x)
{
    int rank = 0;

    while(root != 0)
    {
        if(x == root->value)
            return rank + get_size(root->left) + 1;
        else if(x < root->value)
            root = root->left;
        else
        {
            rank += get_size(root->left) + 1;
            root = root->right;
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, x;
    node *root = 0;
    while(cin >> a && a != 0)
    {
        cin >> x;
        if(a == 1)
            add(root, x);
        else if(a == 2)
            cout << find(root, x) << "\n";
    }
    return 0;
}