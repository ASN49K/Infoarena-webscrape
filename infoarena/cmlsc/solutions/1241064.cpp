#include<iostream>
#include<fstream>
using namespace std;
ifstream g("cmlsc.in");
ofstream f("cmlsc.out");
const int MAX = 1025;
int m, n;
int x[MAX], y[MAX], st, dr, contor = 0, vals[MAX], k = 0, i;
void caut()
{
		for(int j = 0; j < m; j++)
		{
			for(i = contor; i < n; i++)
				if(x[i] == y[j])
				{
					vals[k] = x[i];
					k++;
					contor = i;
					//j++;
					i = n - 1;
				}
		}
		f << k << endl;
		for(int j = 0; j < k; j++)
			f << vals[j] << " ";
}
int main()
{
	g >> n >> m;
	for(int i = 0; i < n; i++)
		g >> x[i];
	for(int i = 0; i < m; i++)
		g >> y[i];
	caut();
}