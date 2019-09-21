#include <iostream>
using namespace std;

int main()
{
	int H, M, t;
	cin >> H >> M;
	t = H * 60 + M;
	if (t >= 860 && t <= 1000) cout << "YES";
	else cout << "NO";
	return 0;
}
