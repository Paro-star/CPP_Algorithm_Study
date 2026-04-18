#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// --- GIỮ NGUYÊN CODE ĐỀ BÀI CHO ---
long long Count = 0;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int pivot, int *a, int n) {
    int left = 0, right = n - 1;
    while (left <= right) {
        while (a[left] < pivot) {
            left++;
            Count++;
        }
        while (a[right] > pivot) {
            right--;
            Count++;
        }
        Count += 2;
        if (left <= right) {
            swap(a[left], a[right]);
            left++;
            right--;
        }
    }
    return left - 1;
}

void quicksort(int *a, int l, int r) {
    if (r > 1) {
        // Pivot = trung bình cộng của 3 vị trí
        int pivot = (a[l] + a[r] + a[(l + r) / 2]) / 3;
        int i = partition(pivot, a + l, r - l + 1);
        quicksort(a, l, i + l);
        quicksort(a, l + i + 1, r);
    }
}
// --- HẾT PHẦN CODE ĐỀ BÀI ---

int main() {
    // Tối ưu nhập xuất
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // CHIẾN THUẬT: Sắp xếp giảm dần để "phá" cách chọn pivot trung bình cộng
    // Điều này khiến partition luôn chia mảng cực kỳ mất cân bằng
    sort(a, a + n, greater<int>());

    // In mảng đã bị đổi trật tự ra (Đây là kết quả bài toán yêu cầu)
    for (int i = 0; i < n; i++) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    // (Phần này để bạn test thử xem Count lớn cỡ nào, khi nộp có thể bỏ)
    // quicksort(a, 0, n - 1);
    // cerr << "Total Count: " << Count << endl;

    delete[] a;
    return 0;
}