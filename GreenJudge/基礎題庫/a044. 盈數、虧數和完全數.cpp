#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n, S = 0;
    cin >> n;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0) S = S + i + n / i;
    }
    S -= n;
    if (S > n) cout << "Abundant";
    else if (S < n) cout << "Deficient";
    else cout << "Perfect";

    return 0;
}