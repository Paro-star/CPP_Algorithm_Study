#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class array_1d
{
    private:
        vector<int> A;
    public:
        //day du lieu vao mang
        void add(int value)
        {
            A.push_back(value);
        }
        //lay du lieu ra de in an
        const vector<int> &get_data() const
        {
            return A;
        }

        vector<int> top_5() const;

        vector<int> tim_k(int k) const;
};

vector<int> array_1d::top_5() const
{
    if(A.size() < 5)
    {
        return {};
    }

    vector<int> mang_tam = A;
    
    partial_sort(mang_tam.begin(), mang_tam.begin() + 5, mang_tam.end(), greater<int>());

    return vector<int>(mang_tam.begin(), mang_tam.begin() + 5);
}

vector<int> array_1d::tim_k(int k) const
{
    vector<int> ds_vt;
    for(size_t i = 0; i < A.size(); i++)
    {
        if(A[i] == k)
            ds_vt.push_back(i);
    }
    return ds_vt;
}

void print_vector(const vector<int> &v)
{
    if(v.empty())
    {
        cout << "khong co du lieu." << endl;
        return;
    }
    for(int x : v)
        cout << x << " ";
    cout << endl;
}

int main()
{
    array_1d arr;
    int tmp;
    cout << "Nhap danh sach (nhap so am de dung): ";
    while(cin >> tmp && tmp >= 0)
    {
        arr.add(tmp);
    }

    int k;
    cout << "nhap gia tri k can tim: ";
    cin >> k;

    cout << "vi tri cua " << k << " can tim la: ";
    print_vector(arr.tim_k(k));
    
    vector<int> top = arr.top_5();

    if(top.empty())
    {
        cout << "khong du 5 phan tu" << endl;
    }
    else
    {
        cout << "top 5 gia tri lon nhat la: ";
        print_vector(top);
    }

    system("pause");
    return 0;
}