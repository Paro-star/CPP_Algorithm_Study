    #include <iostream>

    using namespace std;

    long long find_l(int &d, int &r, long long &n)
    {
        int l =2 * r * n + 2 * d;
        return l;
    }

    int main()
    {
        int d, r;
        long long n;
        cin >> d >> r >> n;
        cout << find_l(d, r, n);
        system("pause");
        return 0;
    }