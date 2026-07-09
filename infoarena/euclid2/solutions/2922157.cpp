#include <iostream>

using namespace std;

typedef long long ll;

int cmmdc(int a, int b)
{
	while (b != 0)
	{
		int aux = a % b;
		a = b;
		b = aux;
	}
	
	return a;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		cmmdc(a, b);
		cout << cmmdc(a, b) << "\n";
	}
	
	return 0;
}