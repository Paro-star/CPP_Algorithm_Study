#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct queue
{
    vector<int> data[5];    //[0] civilian, [1] police, [2] army, [3] fire, [4] ambulance.

    int front[5] = {0, 0, 0, 0, 0};

    void add(int size, string type)
    {
        if(type == "civilian")
            data[0].push_back(size);
        else if(type == "police")
            data[1].push_back(size);
        else if(type == "army")
            data[2].push_back(size);
        else if(type == "fire")
            data[3].push_back(size);
        else if(type == "ambulance")
            data[4].push_back(size);
    };

    void pop(const int l) // cho xe lên đò.
    {
        int cur_length = 0;
        for(int k = 4; k >= 0; k--) // duyệt lần lượt từ vector chứa các xe ưu tiên từ cao xuống thấp.
        {
            while(front[k] < data[k].size() && cur_length + data[k][front[k]] <= l) // nếu vector rỗng hoặc quá tải thì thoát, nếu quá tải mà chưa rỗng thì đi xuống dòng if để double check.
            {
                cur_length += data[k][front[k]];
                front[k]++;  
            }
            if(front[k] < data[k].size()) // nếu còn xe thì break.
                break;
        }
    }

    bool is_empty() // kiểm tra xem còn xe nào đang đợi không
    {
        for(int k = 0; k < 5; k++)
        {
            if(front[k] < data[k].size())  return false; // nếu có hàng nào còn xe thì return false;
        }
        return true;
    }
    void print() // In xe đang đợi ra màn hình.
    {
        string names[5] = {"Civilian: ", "Police: ", "Army: ", "Fire: ", "Ambulance: "};
        for(int i = 0; i < 5; i++)
        {
            cout << names[i];
            for(int j = front[i]; j < data[i].size(); j++) 
                cout << data[i][j] << " ";
            cout << "\n";
        }
        cout << "\n";
    }
};

int solve(queue &left, queue &right, int l) // tính số lần xe chạy.
{
    int count = 0;
    bool at_left = true;
    while(!left.is_empty() || !right.is_empty())
    {
        cout << "Lần thứ "<< count + 1 << "\n";
        cout << "left\n";
        left.print();
        cout << "right\n";
        right.print();
        if(at_left)
        {
            left.pop(l);
        }
        else
        {
            right.pop(l);
        }
        count ++;
        at_left = !at_left;
        
    }
    return count;
}

int main()
{
    int l, m;
    int size; string type; string side;
    cin >> l >> m;
    l *= 100;
    queue left, right;
    while(m--)
    {
        cin >> size >>  type >> side;
        if(side == "left")
            left.add(size, type);
        else if(side == "right")
            right.add(size, type);
    }
    cout << solve(left, right, l) << "\n";
    cout << "so xe con dang cho la\n";
    left.print();
    right.print();
    system("pause");
    return 0;
}