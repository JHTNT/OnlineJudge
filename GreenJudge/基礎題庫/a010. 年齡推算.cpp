#include <iostream>
using namespace std;

int main()
{
    int g, p;
    cin >> g;
    p = (g + 3) % 10+ (g * 2 - 5) / 10 * 10;
    cout << p;
} 