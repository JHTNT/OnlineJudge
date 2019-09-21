#include <iostream>
using namespace std;

int main()
{
	int n, a = 1;
	cin >> n;
	while (n != 1)
	{
		if (n % 2 == 1) n = n * 3 + 1;
		else n /= 2;
		a += 1;
	}
	cout << a;
	return 0;
}
