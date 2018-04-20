#include <iostream>

using namespace std;

// solution 1
void mySwap1(int& a, int& b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

// solution 2
void mySwap2(int& a, int& b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int main()
{
    int a = 100, b = 50;
    mySwap1(a, b);
    cout << a << " " << b << endl;
    mySwap2(a, b);
    cout << a << " " << b << endl;

}