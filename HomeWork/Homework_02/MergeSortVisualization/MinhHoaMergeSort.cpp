#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void print(const vector<int> &a, int l, int r)
{
    int max_val = a[0];
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] > max_val)
            max_val = a[i];
    }

    int h = max_val;
    while(h > 0)
    {
        for(int i = 0; i < a.size(); i++)
        {
            if(a[i] >= h)
            {
                if(i >= l && i < r)
                    cout << "-";
                else 
                    cout << "#";
            }
            else
                cout << " ";
            if(i < a.size() - 1)
                cout << " ";
        }
        cout << endl;
        h--;
    }

}

void merge(vector<int> &a, int l, int m, int r)
{
    vector<int> tmp;
    int i = l;
    int j = m;
    while(i < m && j < r)
    {
        if(a[i] < a[j])
            tmp.push_back(a[i++]);
        else
            tmp.push_back(a[j++]);
    }

    while(i < m)
    {
        tmp.push_back(a[i++]);
    }

    while(j < r)
    {
        tmp.push_back(a[j++]);
    }
    
    for(int i = 0; i < tmp.size(); i++)
    {
        a[l + i] = tmp[i];
    }
}

void merge_sort(vector<int> &a, int l, int r)
{
    if(l >= r - 1)
        return;
    int m = floor(l + (r - l) / 2);
    merge_sort(a, l, m);
    merge_sort(a, m, r);
    merge(a, l, m, r);
    print(a, l, r);
}

int main()
{
    vector<int> a;
    int x;
    while(cin >> x)
    {
        a.push_back(x);
    }
    
    print(a, -1, -1);
    merge_sort(a, 0, a.size());
    print(a, -1, -1);
    
    system("pause");
    return 0;
}