#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    
    vector<long> a(n);
    for(int i = 0; i < a.size(); i++)
    {
        cin >> a[i];
    }

    long x, k;
    cin >> x >> k;

    vector<long> not_x;
    long count_x = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] == x)
            count_x ++;
        else
            not_x.push_back(a[i]);
    }

    if(count_x == 0)
    {
        if(k == n)
        {
            for(int i = 0; i < n; i++)
            {
                cout << a[i] << (i == n - 1 ? "" : " ");
            }
            cout << "\n";
        }
        else
            cout << "IMPOSSIBLE\n";
    }

    else
    {
        if(k > n || not_x.size() < k - 1 || k < 1)
            cout << "IMPOSSIBLE\n";
        else
        {

            auto print = [&](long value)
            {
                cout << value << " ";
            };

            int ptr = 0;
            
            for(int i = 0; i < k - 1; i++)
            {
                print(not_x[ptr++]);
            }

            for(int i = 0; i < count_x; i++)
            {
                print(x);
            }

            while(ptr < not_x.size())
            {
                print(not_x[ptr++]);
            }
            cout << "\n";
        }
    }


}

int main()
{
    int T;
    if((cin >> T))
    {
        while(T--)
        {
            solve();
        }
    }
    system("pause");
    return 0;
}