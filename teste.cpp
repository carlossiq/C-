#include <iostream>
#include <cstdlib> 
#include <ctime>

char line(char array[3][3], int size)
{   
    int counter = 0, i = 0, j = 0;
    for (i = 0, j = 0; i < size-1, j < size-1; i++, j++)
    {
        if(array[i][j] != array[j+1][i+1]) break;
        else return array[0][0];
    }
    return '\0';
}

int main()
{
    int size = 3;
    char array[3][3]={{'o', 'o', 'x'}, {'o', 'x', 'o'}, {'o', 'x', 'x'}};
    std::cout << line(array, size);
    
    
}