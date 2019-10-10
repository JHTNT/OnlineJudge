#include <iostream>
using namespace std;

int main()
{
	int n, r, P, S = 1;
	cin >> n >> r;
	for (P = n; P > n - r; P--)
	{
		S *= P;
	}
	cout << S;
	
	return 0;
}
