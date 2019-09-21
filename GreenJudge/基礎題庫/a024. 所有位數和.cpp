#include <iostream>
using namespace std;

int main()
{
	int n, S = 0;
	cin >> n;
	while (n != 0)
	{
		S += n % 10;
		n /= 10;
	}
	cout << S;
	return 0;
}
