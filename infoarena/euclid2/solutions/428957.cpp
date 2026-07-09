#include <fstream>
using namespace std;

int cmmdc(int a, int b)
{
	if( a % b == 0)
		return b;
	else
		return cmmdc(b, a % b);
}

int main()
{
	int a;
	int b;
	int n;

	ifstream file ("euclid2.in");
	ofstream file2 ("euclid2.out");

	file >> n;
	for (int i = 1; i <= n; i++)
	{
		file >> a;
		file >> b;
		file2 << cmmdc(a, b) << "\n";
	}

	file.close();
	file2.close();
	
	return 0;
}


