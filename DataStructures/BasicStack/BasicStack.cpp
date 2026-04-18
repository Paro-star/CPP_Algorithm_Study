#include <iostream>
#include <vector>

using namespace std;

struct stack
{
    vector<int> st;
    void push(const int val) {st.push_back(val); }
    void pop() {st.pop_back(); }
    int peek() {return st.back(); }
    bool is_empty()
    {
        return st.empty();
    }
};

void PrintStack(const stack &obj)
{
    int n = obj.st.size() - 1;
    cout << "STACK: ";
    for(int i = n; i >= 0; i--)
    {
        cout << obj.st[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int opt, val;
    stack st;
    while(cin >> opt && opt != 4)
    {
        switch (opt)
        {
            case 1:
            {
                cin >> val;
                cout << "pushed\n";
                st.push(val);
                PrintStack(st);
                break;
            }
            case 2:
            {
                if(st.is_empty())
                {
                    cout << "EMPTY\n";
                }
                else
                {
                    cout << st.peek() << "\n";
                    st.pop();
                }
                PrintStack(st);
                break;
            }
            case 3:
            {
                if(st.is_empty())
                {
                    cout << "EMPTY\n";
                }
                else
                {
                    cout << st.peek() << "\n";
                }
                PrintStack(st);
                break;
            }
            default:
                break;
        }
    }
    system("pause");
    return 0;
}