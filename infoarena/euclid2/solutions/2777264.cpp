#include <fstream>
#include <iostream>
using namespace std;
int main()
{
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	int a[10000][2], i, j, n, m = 2, v[10000];
	in >> n;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			in >> a[i][j];
	for (i = 0; i < n; i++)
	{
		while (a[i][0] != a[i][1])
		{
			if (a[i][0] > a[i][1])
				a[i][0] = a[i][0] - a[i][1];
			if (a[i][1] > a[i][0])
				a[i][1] = a[i][1] - a[i][0];
		}
			v[i] = a[i][1];
		
	}
	for (i = 0; i < n; i++)
	{
		out << v[i];
		out<<endl;
	}
	
		

		
}