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

#include <string>
using std::string;

void mais(int *a)
{
    (*a)++;
}

int main()
{
    int a = 10;
    mais(&a);
    cout << a << endl;
}