#include<iostream>

int main()
{
    int array[] = {9,8,7,6,5,4,3,2,1};
    const int size = sizeof(array)/sizeof(array[0]);
    int key = 3;
    for(int i = 0; i < size; i++)
    {
        if(key == array[i])
        {
            std :: cout << " The key found by linear search is at the index: " << i << "\n";
            return 0;
        }
    }
}