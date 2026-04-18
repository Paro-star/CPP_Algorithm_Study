#include <vector>
#include <iostream>
#include <string>

using namespace std;

struct stack
{
    vector<char> data;
    void push(const char x) {data.push_back(x); }
    void pop() {data.pop_back(); }
    char peek() {return data.back(); }
    bool is_empty() {return data.empty(); }
};

bool KiemTraNgoac(const string &s)
{
    stack st;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
        }
        else if(s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            if(st.is_empty())
                return false;
            
            char top = st.peek();
            
            if(s[i] == ')' && top == '(' || 
                s[i] == ']' && top == '[' || 
                s[i] == '}' && top == '{')
                {
                    st.pop();
                }
        }
        else
            return false;
    }
    return st.is_empty();
}

int main()
{
    string s;
    while(true)
    {
        cin >> s;
        if(s == "END")
            break;
        if(KiemTraNgoac(s))
            cout << "TRUE\n";
        else
            cout << "FALSE\n";
    }
    system("pause");
    return 0;
}