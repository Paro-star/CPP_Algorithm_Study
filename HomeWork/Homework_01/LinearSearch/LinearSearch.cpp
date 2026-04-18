#include <vector>
#include <iostream>

using namespace std;

int linear_search(vector<int> &arr, int n, int x)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == x)
            return i;
    }
    return -1;
}

int Rlinear_search(vector<int> &arr, int n, int x)
{
    for(int i = n - 1; i >= 0; i--)
    {
        if(arr[i] == x)
            return i;
    }
    return -1;
}

void nhap(vector<int> &arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}


int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    nhap(A, n);
    int x;
    cin >> x;

    int index = linear_search(A, n, x);
    if(index == -1)
    {
        cout << index << endl;
        return 0;
    }
    int pos1 = index;
    int pos2 = n - Rlinear_search(A, n, x) - 1;
    cout << pos1 << endl;
    cout << pos1 + 1 << endl;
    cout << pos2 << endl;
    cout << pos2 + 1 << endl;
    return 0;
}