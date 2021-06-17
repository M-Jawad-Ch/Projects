//Author: Muhammaad Jawad Chaudhary

#include<iostream>
#include<math.h>
#include<conio.h>
#include<windows.h>

bool test(int*);
void print(int*);

int main()
{
    int i = 0;
    for(int x1 = 0; x1 < 8; x1++)
    {
        for(int x2 = 0; x2 < 8; x2++)
        {
            for(int x3 = 0; x3 < 8; x3++)
            {
                for(int x4 = 0; x4 < 8; x4++)
                {
                    for(int x5 = 0; x5 < 8; x5++)
                    {
                        for(int x6 = 0; x6 < 8; x6++)
                        {
                            for(int x7 = 0; x7 < 8; x7++)
                            {
                                for(int x8 = 0; x8 < 8; x8++)
                                {
                                    int pos[8] = {x1,x2,x3,x4,x5,x6,x7,x8};
                                    if(test(pos))
                                    {
                                        print(pos);
                                        std :: cout << ".\n";
                                        i++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    std :: cout << " Eight Queens Problem\n Total solutions: " << i << std :: endl;
    while(!kbhit())
    {
        
    }
}

bool test(int pos[8])
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(i != j)
            {
                if(pos[i] == pos[j]) return false;
                if(i + pos[i] == j + pos[j]) return false;
                if(i - pos[i] == j - pos[j] || pos[i] - i == pos[j] - j) return false;
            }
        }
    }
    return true;
}

void print(int pos[8])
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(i == pos[j]) std :: cout << "  Q";
            else std :: cout << "  #";
        }
        std :: cout << "\n";
    }
}