#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

class HeapDraw
{
    private:
        vector<int> iHeap;
        vector<int> iRow;
        vector<int> iCol;
        int iCurCol;
        int iMaxRow;
        int iWidth;

        void InOrder(int iIndex, int iDepth)
        {
            if(iIndex >= iHeap.size())
                return;
            InOrder(2 * iIndex + 1, iDepth + 1);
            iRow[iIndex] = iDepth;
            iCol[iIndex] = iCurCol++;
            if(iDepth > iMaxRow)
                iMaxRow = iDepth;
            InOrder(2 * iIndex + 2, iDepth + 1);
        }
        void CalPos(int iVal, int iCol, int &iStart, int &iEnd)
        {

            int iLen = to_string(iVal).length();
            int iPadding = iWidth - iLen;
            int LeftPad, RightPad;
            if(!(iPadding & 1))
            {
                LeftPad = RightPad = iPadding / 2;
            }
            else
            {
                if(!(iLen & 1))
                {
                    LeftPad = iPadding / 2 + 1;
                    RightPad = iPadding / 2;
                }
                else
                {
                    LeftPad = iPadding / 2;
                    RightPad = iPadding / 2 + 1;
                }
            }
            iStart = iCol * iWidth + LeftPad;
            iEnd = iStart + iLen - 1;
        }
    public:
        HeapDraw(const vector<int> data)
        {
            iHeap = data;
            int n = iHeap.size();
            iRow.assign(n, 0);
            iCol.assign(n, 0);
            iCurCol = 0;
            iMaxRow = 0;

            int MaxDigit = 0;
            {
                for(auto x : iHeap)
                {
                    int iDigit = to_string(x).length();
                    if(iDigit > MaxDigit)
                        MaxDigit = iDigit;
                }
            }
            iWidth = MaxDigit + 4;
            InOrder(0, 0);
        }

        void Draw()
        {
            if(iHeap.empty())
                return;
            int iHeight = iMaxRow + 1;
            int W = iCurCol * iWidth;
            vector<string> canvas(iHeight, string(W, ' '));
            for(int i = 0; i < iHeap.size(); i++)
            {
                int iStart, iEnd;
                CalPos(iHeap[i], iCol[i], iStart, iEnd);

                string sVal = to_string(iHeap[i]);
                for(auto k = 0; k < sVal.length(); k++)
                    canvas[iRow[i]][iStart + k] = sVal[k];

                int iLeft = 2 * i + 1;
                if(iLeft < iHeap.size())
                {
                    int ilStart, ilEnd;
                    CalPos(iHeap[iLeft], iCol[iLeft], ilStart, ilEnd);
                    for(auto k = ilEnd + 1; k < iStart; k++)
                    {
                        canvas[iRow[i]][k] = '.';
                    }
                }

                int iRight = 2 * i + 2;
                if(iRight < iHeap.size())
                {
                    int irStart, irEnd;
                    CalPos(iHeap[iRight], iCol[iRight], irStart, irEnd);
                    for(auto k = iEnd + 1; k < irStart; k++)
                    {
                        canvas[iRow[i]][k] = '.';
                    }
                }
            }
            for(int r = 0; r < iHeight; r++)
            {
                int LastChar = W - 1;
                while(LastChar >= 0 && canvas[r][LastChar] == ' ')
                    LastChar--;
                if(LastChar >= 0)
                    cout << canvas[r].substr(0, LastChar + 1) << "\n";
                else
                    cout << "\n";
            }
        }
};

int main()
{
    vector<int> input_data;
    int x;

    while (cin >> x) {
        input_data.push_back(x);
    }

    if (!input_data.empty()) {
        HeapDraw hd(input_data);
        hd.Draw();
    }
    system("pause");
    return 0;
}