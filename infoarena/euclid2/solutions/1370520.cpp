#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

int euclid(int a, int b)
{
	int r;

	while (b)
	{
		r = a % b;
		a = b;
		b = r;

	}
	return a;
}

int main()
{
	ifstream f1("euclid2.in");
	ofstream f2("euclid2.out");

	int a, b, n;

	f1 >> n;

	for(int i=0; i<n; i++)
    {
        f1>>a>>b;
        a = euclid(a, b);
        f2<<a;
    }
    f1.close();
    f2.close();
	return 0;
}
