#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	if (b % 3 == 2) cout << "200";
	else if (a % 2 == 1) cout << "100";
	else if (a == b) cout << "50";
	else cout << "0";
	return 0;
}
