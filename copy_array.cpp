#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <algorithm>
using std::copy;

#include <vector>
using std::vector;

#include <cassert>

#include <cmath>

int main()
{
    size_t a = 0, b = 6;
    int array_[] = {10, 8, 6, 4, 2, 0};
    int *arrrray = array_;
    int *array = new int[10];

    copy(arrrray + a, arrrray + b, array); //copy trabalha com os iteradores

    for(int i = 0; i < 6; i++) cout << array_[i] << " ";
}