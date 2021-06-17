#include<iostream>
int main()
{
    int array[] = {0,1,2,3,4,5,6,7,8,9};
    int size = sizeof(array)/sizeof(array[0]);
    int ends[2] = {0,size - 1}, mid = (ends[1]/2), key = 2;
    while(ends[1] - ends[0] > 2)
    {
        if(key > array[mid])
        {
            ends[0] = mid;
        }
        else if(key < array[mid])
        {
            ends[1] = mid; 
        }
        else
        {
            std :: cout << " The key found by binary search is at the index: " << mid << "\n";
            return 0;
        }
        mid = (ends[1] + ends[0])/2;
    }
    for(int i = ends[0]; i <= ends[1]; i++)
    {
        if(array[i] == key)
        {
            std :: cout << " The key found by binary search is at the index: " << i << "\n";
            return 0;
        }
    }
}