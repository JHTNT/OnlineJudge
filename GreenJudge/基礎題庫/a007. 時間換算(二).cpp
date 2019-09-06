#include <iostream>
using namespace std;

int main()
{
    int H, M;
    cin >> M;
    H = M / 60;
    M = M % 60; 
    cout << H << " " << M;
} 