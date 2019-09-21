#include <iostream>
using namespace std;

int main()
{
	int a, b, s = 0;
	cin >> a >> b;
	if (b % 3 == 2) s += 200;
	if (a % 2 == 1) s += 100;
	if (a == b) s += 50;
	cout << s;
	return 0;
}
