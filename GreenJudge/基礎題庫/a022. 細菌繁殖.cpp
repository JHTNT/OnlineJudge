#include <iostream>
using namespace std;

int main()
{
	int n, m, t = 0;
	cin >> n >> m;
	while (n < m)
	{
		n *= 3;
		t += 1;	
	}
	cout << t;
	return 0;
}
