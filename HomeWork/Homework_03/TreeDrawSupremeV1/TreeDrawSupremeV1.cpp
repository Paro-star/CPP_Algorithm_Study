//
// Created by duong on 4/28/2026.
//
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// Cấu trúc của một Nhánh cây (Node)
struct Node {
    int key;       // Giá trị của node
    int size;      // Tổng số node con cháu (bao gồm cả nó)
    int col;       // "Kinh độ" (Cột X) trên bản đồ vẽ
    int row;       // "Vĩ độ" (Hàng Y) trên bản đồ vẽ, chính là độ sâu của cây
    Node *left = 0, *right = 0;

    // Khởi tạo mặc định: chưa có con, size = 1 (chính nó)
    Node (int x) : key(x), size(1), left(0), right(0) {}
};

// Bản ghi nhớ dữ liệu vẽ: Biến các Node rải rác thành một danh sách dễ quản lý
struct DrawInfo {
    int key, row, col;
    string nums; // Giá trị dạng chuỗi (để dễ đo chiều dài)

    // Các biến static này dùng chung cho toàn bộ chương trình,
    // Mục đích là dò tìm xem cái "Bức tranh" cuối cùng sẽ to cỡ nào.
    inline static int max_row = 0;   // Đáy bức tranh nằm ở đâu?
    inline static int max_col = 0;   // Cạnh phải bức tranh nằm ở đâu?
    inline static int max_digit = 0; // Con số dài nhất chiếm bao nhiêu ký tự? (VD: 393 -> 3)
};

// Hàm nhét thêm Node mới vào cây Nhị Phân Tìm Kiếm (BST)
bool add(Node * & root, int x) {
    if (root == 0) { // Chỗ trống đây rồi, cắm rễ thôi!
        root = new Node(x);
        return true;
    }
    if (root->key == x) return false; // Trùng số thì bỏ qua

    bool added = false;
    // Lớn hơn thì tạt sang phải, nhỏ hơn thì rẽ sang trái
    if (root->key < x)
        added = add(root->right, x);
    else
        added = add(root->left, x);

    // Nếu nhét thành công ở dưới, thì update lại quân số (size) cho node cha
    if (added) root->size += 1;
    return added;
}

// Hàm cốt lõi: Vừa duyệt cây, vừa cấp phát Tọa độ (Hàng, Cột)
// Tại sao lại dùng InOrder (Trái - Gốc - Phải)?
// Vì khi in ra màn hình, Node con trái luôn nằm bên trái Gốc, con phải luôn nằm bên phải.
// Duyệt InOrder sẽ đi từ trái sang phải màn hình, cực kỳ khớp với trục X (biến cur)!
void inOrder(vector<DrawInfo> &A, Node * root, int depth, int &cur) {
    if (root == 0) return;

    // 1. Đi sâu xuống tận cùng bên trái
    inOrder(A, root->left, depth + 1, cur);

    // 2. Xử lý Node hiện tại: Chốt sổ tọa độ cho nó
    root->col = cur;    // Cột dọc hiện tại
    root->row = depth;  // Độ sâu chính là hàng ngang

    string nums = to_string(root->key);
    int digit = nums.length();

    // Lưu hồ sơ của node này vào mảng A để lát nữa vẽ
    A.push_back({root->key, depth, cur, nums});

    // Cập nhật kỷ lục kích thước của bức tranh nếu có
    if (cur > DrawInfo::max_col) DrawInfo::max_col = cur;
    if (depth > DrawInfo::max_row) DrawInfo::max_row = depth;
    if (digit > DrawInfo::max_digit) DrawInfo::max_digit = digit;

    cur ++; // Dịch sang cột X tiếp theo ở bên phải

    // 3. Xử lý nốt nhánh bên phải
    inOrder(A, root->right, depth + 1, cur);
}

// Hàm in để debug cấu trúc cây (không xài tới trong quá trình vẽ)
void DUMP(Node * root) {
    if (root == 0) return;
    cout << root << " "
        << root->key << " "
        << root->size << " "
        << root->left << " "
        << root->right << endl;
    DUMP(root->left);
    DUMP(root->right);
}

// Hàm in các tọa độ đã thu thập được để kiểm tra (Test xem hàm inOrder chạy đúng không)
void Print(const vector<DrawInfo> &A) {
    for (auto i : A) {
        cout << i.key << " " << i.row << " " << i.col << endl;
    }
    cout << "---------------------" << endl;
    cout << DrawInfo::max_row << " " << DrawInfo::max_col << " " << DrawInfo::max_digit << endl;
}

// Hàm "Đắp Gạch": Đưa các con số vào đúng tọa độ trên khung tranh (canvas)
void TreeDraw(const vector<DrawInfo> &A, vector<string> &canvas) {
    for (int i = 0; i < A.size(); i++) {
        int y = A[i].row; // Hàng thì giữ nguyên
        int x = A[i].col * DrawInfo::max_digit; // Cột phải nhân với độ béo của số (để chừa chỗ)

        string s = A[i].nums;
        // Đệm thêm số '0' ở đầu nếu số đó ngắn hơn max_digit (VD: 3 -> 003)
        while (s.length() < DrawInfo::max_digit) {
            s = "0" + s;
        }

        // Đắp từng ký tự của con số lên bản vẽ canvas
        for (int j = 0; j < DrawInfo::max_digit; j++) {
            canvas[y][x + j] = s[j];
        }
    }
}

// Hàm "Kéo Dây": Rải các dấu chấm (.) để nối Node Cha với Node Con
void DrawDot(Node * root, vector<string> &canvas) {
    if (root == 0) return;

    int max_digit = DrawInfo::max_digit;

    // Rải dây sang con Trái
    if (root->left != 0) {
        // Bắt đầu từ khoảng trống ngay bên phải con Trái
        int start = (root->left->col + 1) * max_digit;
        // Kéo dài đến sát vách bên trái của Cha
        int end = root->col * max_digit;

        // Vẽ dây trên CÙNG MỘT HÀNG ngang với Cha
        for (int i = start; i < end; i++) {
            canvas[root->row][i] = '.';
        }
        DrawDot(root->left, canvas); // Đi xuống đệ quy tiếp
    }

    // Rải dây sang con Phải
    if (root->right != 0) {
        // Bắt đầu từ khoảng trống ngay bên phải Cha
        int start = (root->col + 1) * max_digit;
        // Kéo dài đến sát vách bên trái của con Phải
        int end = root->right->col * max_digit;

        for (int i = start; i < end; i++) {
            canvas[root->row][i] = '.';
        }
        DrawDot(root->right, canvas);
    }
}

int main() {
    // Tối ưu hóa luồng I/O để cin/cout chạy nhanh như gió
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x;
    Node * root = 0;

    // Đọc liên tục cho đến khi gặp số 0 thì dừng
    while (cin >> x && x != 0) {
        add(root, x);
    }

    // Bước 1: Khảo sát và lấy Tọa độ
    vector<DrawInfo> A;
    int start = 0; // Bắt đầu ở cột 0
    inOrder(A, root, 0, start);

    // Bước 2: Chuẩn bị Khung tranh (Canvas)
    int total_high = DrawInfo::max_row + 1; // Tổng số dòng
    int total_width = (DrawInfo::max_col + 1) * DrawInfo::max_digit; // Tổng chiều dài ngang

    DUMP(root); // In Toàn bộ thông số của cây ra màn hình
    Print(A); // In mớ data thô ra soi thử

    // Tạo bức tranh trống, phủ toàn bằng dấu cách (space)
    vector<string> canvas(total_high, string(total_width, ' '));

    // Bước 3: Đưa nét vẽ lên tranh
    TreeDraw(A, canvas);    // Đắp số vào
    DrawDot(root, canvas);  // Kéo đường chấm

    // Bước 4: Triển lãm (in bức tranh ra terminal)
    for (int i = 0; i < canvas.size(); i++) {
        cout << canvas[i] << endl;
    }

    return 0;
}