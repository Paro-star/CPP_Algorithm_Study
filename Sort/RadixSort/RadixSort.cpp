#include <iostream>
#include <vector>

using namespace std;

int get_max(const vector<int> &A)
{
    int max_val = A[0];
    for(int i = 1; i < A.size(); i++)
    {
        if(max_val < A[i])
        {
            max_val = A[i];
        }
    }
    return max_val;
}

void counting_sort(vector<int> &A, int exp)
{
    int n = A.size();
    vector<int> output(n, 0);
    int count[10] = {0};

    for(int i = 0; i < n; i++)
    {
        int digit = (A[i] / exp) % 10;
        count[digit] += 1;
    }

    for(int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }


    for(int i = n - 1; i >= 0; i--)
    {
        int digit = (A[i] / exp) % 10;
        output[count[digit] - 1] = A[i];
        count[digit] -= 1;
    }

    for(int i = 0; i < A.size(); i++)
    {
        A[i] = output[i];
    }
}

void RadixSort(vector<int> &A)
{
    if(A.empty())
        return;
    int max_val = get_max(A);
    for(int exp = 1; max_val / exp > 0; exp *= 10)
    {
        counting_sort(A, exp);
    }
}

void Nhap(vector<int> &A) {
    int tmp;
    cout << "Nhap cac so (nhap chu de thoat): " << endl;
    while(true) {
        if (!(cin >> tmp)) { // Neu nhap ko phai la so
            break;           // Thoat ngay lap tuc
        }
        A.push_back(tmp);
    }
    cin.clear();
    cin.ignore(10000, '\n');
}

void Xuat(vector<int> &A)
{
    for(int x : A)
        cout << x << " ";
    cout << endl;
}  

int main()
{
    vector<int> A;
    Nhap(A);
    RadixSort(A);
    Xuat(A);
    system("pause");
    return 0;
}