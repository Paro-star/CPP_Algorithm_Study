#include <vector>
#include <iostream>
#include <string>
#include<algorithm>

using namespace std;

class HeapDraw
{
private:
    vector<int> Heap;
    vector<int> Row;
    vector<int> Col;
    int CurCol;
    int MaxRow;
    int Width;
    int DownIndex;
    int UpIndex;

    void InOrder(int Index, int Depth)
    {
        if(Index >= Heap.size())
            return;
        InOrder(2 * Index + 1, Depth + 1);
        Row[Index] = Depth;
        Col[Index] = CurCol++;
        if(Depth > MaxRow)
            MaxRow = Depth;
        InOrder(2 * Index + 2, Depth + 1);
    }

    void CalPos(int Val, int Index, int &Start, int &End)
    {
        int Digit = to_string(Val).size();
        int Padding = Width - Digit;
        int LeftPad, RightPad;
        if(!(Padding & 1))
        {
            LeftPad = RightPad = Padding / 2;
        }
        else
        {
            if(!(Digit & 1))
            {
                LeftPad = Padding / 2 + 1;
                RightPad = Padding / 2;
            }
            else
            {
                LeftPad = Padding / 2;
                RightPad = Padding / 2 + 1;
            }
        }
        Start = Col[Index] * Width + LeftPad;
        End = Start + Digit - 1;
    }
public:
    HeapDraw(const vector<int> &InputData, int Down = - 1, int Up = -1)
    {
        if(InputData.empty())
            return;

        DownIndex = Down;
        UpIndex = Up;
        Heap = InputData;
        int n = Heap.size();

        Row.assign(n, 0);
        Col.assign(n, 0);

        CurCol = 0;
        MaxRow = 0;

        int Max_digit = to_string(Heap[0]).size();
        for(auto x : Heap)
        {
            int Tmp = to_string(x).size();
            if(Tmp > Max_digit)
            {
                Max_digit = Tmp;
            }
        }
        InOrder(0, 0);
        Width = Max_digit + 4;
    }

    void Draw()
    {
        int W = CurCol * Width;
        vector<string> Canvas(MaxRow + 1, string(W, ' '));
        for(int i = 0; i < Heap.size(); i++)
        {
            string Val = to_string(Heap[i]);
            int Start, End;
            CalPos(Heap[i], i, Start, End);
            for(int k = 0; k < Val.size(); k++)
            {
                Canvas[Row[i]][Start + k] = Val[k];
            }

            int LeftIndex = 2 * i + 1;
            if(LeftIndex < Heap.size())
            {
                int LeftStart, LeftEnd;
                CalPos(Heap[LeftIndex], LeftIndex, LeftStart, LeftEnd);
                for(int k = LeftEnd + 1; k < Start; k++)
                {
                    Canvas[Row[i]][k] = '.';
                }
            }

            int RightIndex = 2 * i + 2;
            if(RightIndex < Heap.size())
            {
                int RightStart, RightEnd;
                CalPos(Heap[RightIndex], RightIndex, RightStart, RightEnd);
                for(int k = End + 1; k < RightStart; k++)
                {
                    Canvas[Row[i]][k] = '.';
                }
            }
            if(i == UpIndex || i == DownIndex)
            {
                char arrow = (i == UpIndex) ? 24 : 25;
                char space = ' ';
                Canvas[Row[i]][Start - 2] = arrow;
                Canvas[Row[i]][Start - 1] = arrow;
                Canvas[Row[i]][End + 1] = arrow;
                Canvas[Row[i]][End + 2] = arrow;
                if(Row[i] > 0)
                {
                    Canvas[Row[i] - 1][Start - 2] = space;
                    Canvas[Row[i] - 1][Start - 1] = space;
                    Canvas[Row[i] - 1][End + 1] = space;
                    Canvas[Row[i] - 1][End + 2] = space;
                }
            }
        }
        for(int r = 0; r <= MaxRow; r++)
        {
            int LastChar = W - 1;
            while(LastChar >= 0 && Canvas[r][LastChar] == ' ')
                LastChar--;
            if(LastChar >= 0)
            {
                cout << Canvas[r].substr(0, LastChar + 1) << "\n";
            }
            else
                cout << "\n";
        }
    }

};

void BuildMaxHeap(vector<int> &data, int i, int n)
{
    int max_index = i;
    int left_index = 2 * i + 1;
    int right_index = 2 * i + 2;


    if(left_index < n && (data[left_index]) > data[max_index])
        max_index = left_index;

    if(right_index < n && (data[right_index] > data[max_index]))
        max_index = right_index;

    if(max_index != i)
    {
        swap(data[i], data[max_index]);

        HeapDraw stepDraw(data, i, max_index);
        stepDraw.Draw();

        BuildMaxHeap(data, max_index, n);
    }
}

void HeapSort(vector<int> &data)
{
    HeapDraw X(data);
    int n = data.size();
    for(int i = n / 2 - 1; i >= 0; i--)
    {
        BuildMaxHeap(data, i, n);
    }
    for(int i = n - 1; i > 0; i--)
    {
        swap(data[0], data[i]);
        BuildMaxHeap(data, 0, i);
        X.Draw();
    }
}
int main()
{
    vector<int> data;
    int x;
    while(cin >> x)
    {
        data.push_back(x);
    }
    //HeapSort(data);
    HeapDraw Ori(data);
    Ori.Draw();
    for(int i = data.size() / 2 - 1; i >= 0; i--)
    {
        cout  << "Đẩy giá trị " << data[i] << " tại vị trí " << i << " xuống (nếu cần)\n";
        BuildMaxHeap(data, i, data.size());
    }
    system("pause");
    return 0;
}