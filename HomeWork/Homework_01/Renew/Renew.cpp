#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, k, m, n;
    cin >> a >> k >> b >> m >> n;

    auto check = [&](long long mid)
    {
        return (unsigned __int128)(mid - mid / k) * a + (unsigned __int128)(mid - mid / m) * b >= n;
    };

    long long left = 1, right = 2e18, ans = right;
    while(left <= right)
    {
        long long mid = left + (right - left) / 2;
        check(mid) ? (ans = mid, right = mid - 1) : (left = mid + 1);   
    }
    cout << ans;
    return 0;
}