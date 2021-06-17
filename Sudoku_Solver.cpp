#include<iostream>
#include<conio.h>
#include<windows.h>

int array[9][9] =  {{5,3,0,   0,7,0,  0,0,0},
                    {6,0,0,   1,9,5,  0,0,0},
                    {0,9,8,   0,0,0,  0,6,0},
                    
                    {8,0,0,   0,6,0,  0,0,3},
                    {4,0,0,   8,0,3,  0,0,1},
                    {7,0,0,   0,2,0,  0,0,6},
                    
                    {0,6,0,   0,0,0,  2,8,0},
                    {0,0,0,   4,1,9,  0,0,5},
                    {0,0,0,   0,8,0,  0,7,9}};

void print()
{
    std :: cout << " ___________________________________\n";
    std :: cout << "|           |           |           |\n";
    for(int i = 0; i < 9; i++)
    {
        std :: cout << "|";
        for(int j = 0; j < 9; j++)
        {
            if(j == 3 || j == 6)
            {
                std :: cout << "  |  ";
                if(array[i][j] == 0) std :: cout << " ";
                else std :: cout << array[i][j];
            }
            else if(array[i][j] != 0) std :: cout << "  " << array[i][j];
            else std :: cout << "   ";
        }
        std :: cout << "  |\n";
        if(i == 2 || i == 5) std :: cout << "|-----------|-----------|-----------|\n";
    }
    std :: cout << "|___________|___________|___________|\n";
}
bool Checker(int i, int j, int n)
{
    if(array[i][j] != 0) return false;
    for(int x = 0; x < 9; x++)
    {
        if(array[x][j] == n && x != i) return false;
        else if(array[i][x] == n && x != j) return false;
    }

    int cube[2];
    if(i > 2)
    {
        if(i > 5) cube[1] = 6;
        else cube[1] = 3;
    }
    else cube[1] = 0;
    if(j > 2)
    {
        if(j > 5) cube[0] = 6;
        else cube[0] = 3;
    }
    else cube[0] = 0;

    for(int y = cube[1]; y < cube[1] + 3; y++)
    {
        for(int x = cube[0]; x < cube[0] + 3; x++)
        {
            if(array[y][x] == n)
            {
                if(y != i && x != j)return false;
            }
        }
    }
    return true;
}
int PlaceChecker(int i, int j, int n)
{
    int cube[2];
    if(i > 2)
    {
        if(i > 5) cube[1] = 6;
        else cube[1] = 3;
    }
    else cube[1] = 0;
    if(j > 2)
    {
        if(j > 5) cube[0] = 6;
        else cube[0] = 3;
    }
    else cube[0] = 0;

    for(int i1 = cube[1]; i1 < cube[1] + 3; i1++)
    {
        for(int j1 = cube[0]; j1 < cube[0] + 3; j1++)
        {
            if(i1 == i && j1 == j) continue;
            else if(Checker(i1,j1,n)) return false;
        }
    }
    return true;
}
void SudokuSolver()
{
    while(true)
    {
        for(int n = 1; n < 10; n++)
        {
            for(int i = 0; i < 9; i++)
            {
                for(int j = 0; j < 9; j++)
                {
                    if(array[i][j] == 0)
                    {
                        if(Checker(i,j,n))
                        {
                            if(PlaceChecker(i,j,n))
                            {
                                array[i][j] = n;
                            }
                        }
                    }
                }
            }
        }
        bool completion = true;
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(array[i][j] == 0) completion = false;
            }
        }
        if(completion) break;
    }
}

int main()
{
    print();
    SudokuSolver();
    print();
}