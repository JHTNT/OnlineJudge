#include <iostream>
using namespace std;

int main()
{
	int n, i;
	cin >> n;
	for (i = n; i >= 0; i--)
	{
		if (i == 0) cout << 0 << endl;
		else cout << i << " ";
	}
	
	return 0;
}
