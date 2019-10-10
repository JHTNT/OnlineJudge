#include <iostream>
using namespace std;

int main()
{
	int a, b, i, S = 0;
	cin >> a >> b;
	if (a <= b)
	{
		for (i = a; i < b; i++)
		{
			cout << i << "+";
			S += i;
		}
		cout << i << "=" << S + i << endl;
	}
	else if (a > b)
	{
		for (i = a; i > b; i--)
		{
			cout << i << "+";
			S += i;
		}
		cout << i << "=" << S + i << endl;
	}
	
	return 0;
}
