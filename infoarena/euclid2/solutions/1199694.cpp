#include<fstream>
using namespace std;
int cmmdc(int a,int b)
{
	while (a != b)
		if (a > b)
			a = a - b;
		else
			b = b - a;
	return a;
}
int main()
{
	ifstream intrare("euclid2.in");
	ofstream iesire("euclid2.out");
	int n,i;
	intrare >> n;
	for (i = 1; i <= n; i++)
	{
		int a, b;
		intrare >> a >> b;
		iesire<<cmmdc(a, b)<<endl;
	}
	intrare.close();
	iesire.close();
	return 0;
}