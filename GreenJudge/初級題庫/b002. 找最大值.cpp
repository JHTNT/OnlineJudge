#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n, pos, max;
    while (cin >> n)
    {
        pos = 0;
        max = 0;
        int number[10] = {0};
        for (int i = 0; i < n; i++) cin >> number[i];
        for (int i = 0; i < n; i++)
        {
            if (number[i] > max)
            {
                max = number[i];
                pos = i + 1;
            }
        }
        cout << pos << " " << max << endl;
    }
    return 0;
}