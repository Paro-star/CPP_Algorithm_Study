#include <iostream>
#include <vector>

using namespace std;

int get_max(const vector<int> &arr)
{
    int n = arr.size();
    int max_val = arr[0];
    for(int i = 0; i < n; i++)
    {
        if(max_val < arr[i])
            max_val = arr[i];
    }
    return max_val;
}

void counting_sort(vector<int> &arr)
{
    int n = arr.size();
    vector<int> tmp(get_max(arr) + 1, 0);
    for(int i = 0; i < n; i++)
    {
        tmp[arr[i]] += 1;
    }

    for(int i = 1; i < tmp.size(); i++)
    {
        tmp[i] += tmp[i - 1];
    }

    vector<int> output(n, 0);
    for(int i = n - 1; i >= 0; i--)
    {
        output[tmp[arr[i]] - 1] = arr[i];
        tmp[arr[i]] -= 1;
    }

    for(int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void Nhap(vector<int> &arr)
{
    int tmp;
    cout << "Nhap gia tri cho mang(nhap ky tu de thoat): ";
    while(true)
    {
        if(!(cin >> tmp))
            break;
        arr.push_back(tmp);
    }
}

void Xuat(const vector<int> &arr)
{
    for(int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> A;
    Nhap(A);
    counting_sort(A);
    Xuat(A);
    system("pause");
    return 0;
}