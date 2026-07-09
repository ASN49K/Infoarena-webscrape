#include <fstream>

using namespace std;

int n, x;

int main()
{
    ifstream cin("nim.in");
    ofstream cout("nim.out");
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		long long s = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> x;
			s ^= x;
		}
		bool ura = false;
		if (s == 0)
		{
			ura = true;
		}
		if (ura) {
			cout << "NU\n";
		}
		else {
			cout << "DA\n";
		}
	}
	return 0;
}


