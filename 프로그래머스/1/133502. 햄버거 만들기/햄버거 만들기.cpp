#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool IsPossible(vector<int>& Ingredient, int Pos)
{
    if (Pos - 3 < 0) return false;
    
    if (Ingredient[Pos] == 1 &&
       Ingredient[Pos - 1] == 3 &&
       Ingredient[Pos - 2] == 2 &&
       Ingredient[Pos - 3] == 1)
    {
        return true;
    }
    
    return false;
}

int solution(vector<int> Ingredient) {
    int Answer = 0;
    
    while (true)
    {
        bool bIsMade = false;
        for (int i = 0; i < Ingredient.size();)
        {
            if (IsPossible(Ingredient, i))
            {
                Answer++;
                bIsMade = true;
                Ingredient.erase(Ingredient.begin() + (i - 3), Ingredient.begin() + (i + 1));
                i = i - 3;
            }
            else i++;
        }
        
        if (bIsMade == false) break;
    }
    return Answer;
}