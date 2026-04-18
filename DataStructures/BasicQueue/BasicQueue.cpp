#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct queue
{
    vector<int> data;
    int front = 0;
    void push(const int value) {data.push_back(value); }
    int pop()
    {
        if(front >= data.size() / 2 && data.size() > 0)
        {
            move(data.begin() + front, data.end(), data.begin());
            data.resize(data.size() - front);
            front = 0;
        }
        return data[front++];
    }
    bool is_empty()
    {
        return front >= data.size();
    }
    int peek() {return data[front]; }
};

void print_queue(const queue &q)
{
    cout << "QUEUE: ";
    for(int i = q.front; i <q.data.size(); i++)
    {
        cout << q.data[i] << " ";
    }
    cout << "\n";
}

int main()
{
    queue qe;
    int choice, val;
    while(cin >> choice && choice != 4)
    {
        switch (choice)
        {
            case 1:
                cin >> val;
                cout << "pushed\n";
                qe.push(val);
                print_queue(qe);
                break;
            case 2:
                if(qe.is_empty())
                    cout << "EMPTY\n";
                else
                {
                    cout << qe.peek() << "\n";
                    qe.pop();
                }
                print_queue(qe);
                break;
            case 3:
                if(qe.is_empty())
                    cout << "EMPTY\n";
                else
                    cout << qe.peek() << "\n";
                print_queue(qe);
                break;
            default:
                break;
        }   
    }
    system("pause");
    return 0;
}