#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    if (N % 4 != 0) cout << "NO";
    else if (N % 100 != 0) cout << "YES";
    else if (N % 400 != 0) cout << "NO";
    else cout << "YES";
}