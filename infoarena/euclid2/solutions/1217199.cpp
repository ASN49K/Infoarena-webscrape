#include<iostream>
using namespace std;

//input/output files
ifstream f("euclid.in");
ofstream g("euclid.out");

int aux,n,x,y;

int cmmdc(int a, int b)
{
	while(b != 0)
	{
		aux = b;
		b = b % a;
		a = aux;
	}

	return a;

}

int main()
{
	f >> n;
	
	for(int i = 1; i <= n; i++)
	{
		f >> x;
		f >> y;
		g << cmmdc(x,y);
	}
	

		return 0;
}
