#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int m, n;
vector<int> a, b, sir, poz;

int main (int argc, char const *argv[])
{
	ifstream in ("cmlsc.in");
	in >> m >> n;
	a.resize(m);
	b.resize(n);
	for (int i = 0; i < m; i++)
		in >> a[i];
	for (int i = 0; i < n; i++)
		in >> b[i];
	in.close();
	
	/*
	for (int i = 0; i < m; i++)
		cout << a[i] << ' ';
	cout << '\n';
	for (int i = 0; i < n; i++)
		cout << b[i] << ' ';
	cout << '\n';
	*/
	
	sir.resize(n);
	poz.resize(n);
	sir[m - 1] = 1;
	poz[m - 1] = -1;
	for (int i = m - 2; i >= 0; i--)
	{
		poz[i] = -1;
		for (int j = i + 1; j < m; j++)
		{
			if (a[j] > a[i] && sir[i] < sir[j] + 1)
			{
				bool found = false;
				for (int k = n - 1; k >= 0; k--)
				{
					if (b[k] == a[j])
						found = true;
					if (b[k] == a[i] && found)
					{
						sir[i] = sir[j] + 1;
						poz[i] = j;
					}
				}
			}
		}
	}
	
	/*
	for (int i = 0; i < m; i++)
		cout << poz[i] << ' ';
	cout << '\n';
	*/
	
	int max = 0, tar = 0;
	for (int i = 0; i < m; i++)
	{
		if (sir[i] > max)
		{
			max = sir[i];
			tar = i;
		}
	}
	
	/*
	for (int i = tar; i != -1; i = poz[i])
	{
		cout << a[i] << ' ';
	}
	cout << '\n';
	*/
	
	ofstream out ("cmlsc.out");
	out << max << '\n';
	for (int i = tar; i != -1; i = poz[i])
	{
		out << a[i] << ' ';
	}
	out << '\n';
	out.close();	
	
	return 0;
}
