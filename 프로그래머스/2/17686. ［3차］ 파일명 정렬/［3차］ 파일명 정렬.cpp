#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Node
{
    string Head;
    int Number;
    int Pos;
    
    Node(string NewHead, string NewNumber, int NewPos)
    {
        Head = NewHead;
        transform(Head.begin(), Head.end(), Head.begin(), ::tolower);
        
        Number = stoi(NewNumber);
        
        Pos = NewPos;
    }
};

vector<Node> Vector;

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    string HEAD;
    string NUMBER;
    string TAIL;
    
    for (int i = 0; i < files.size(); ++i)
    {
        bool bFindNumber = false;
        int NumberStart;
        int NumberEnd;
        for (int j = 0; j < files[i].size(); ++j)
        {
            if (!bFindNumber)
            {
                if ('0' <= files[i][j] && files[i][j] <= '9')
                {
                    bFindNumber = true;
                    NumberStart = j;
                    NumberEnd = j;
                }
            }
            else
            {
                if ('0' <= files[i][j] && files[i][j] <= '9')
                {
                    NumberEnd = j;
                }
                else break;
            }
        }
        
        HEAD = files[i].substr(0, NumberStart);
        NUMBER = files[i].substr(NumberStart, NumberEnd - NumberStart + 1);
        TAIL = files[i].substr(NumberEnd + 1);
        
        // 파일을 세 부분으로 나눈 후,
        
        Vector.push_back(Node(HEAD, NUMBER, i));
    }
    
    sort(Vector.begin(), Vector.end(), [](Node& A, Node& B)->bool
         {
             if (A.Head == B.Head)
             {
                 if (A.Number == B.Number)
                 {
                     return A.Pos < B.Pos;
                 }
                 
                 return A.Number < B.Number;
             }
             
             return A.Head < B.Head;
         });
    
    for (auto& Iter : Vector)
    {
        answer.push_back(files[Iter.Pos]);
    }
    cout << '\n';
    
    return answer;
}