#include <iostream>
using namespace std;

int main()
{
    int a, b, c, small;
    cin >> a >> b >> c;
    if (a <= b) small = a;
    else small = b;
    if (small >= c) small = c;
    cout << small;
} 