#include <iostream>
using namespace std;

int main()
{
    char a;
    cout << "Enter a: ";
    cin >> a;
    char z = 'z';
    char Z = 'Z';
    int diff = z - Z;
    char b = a - diff;
    cout << "Capital: " << b;
    return 0;
}
