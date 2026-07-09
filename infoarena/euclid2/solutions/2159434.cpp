#include<iostream>
#include<fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int euclid(int a,int b)
{
	int c;
	while(b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

void rezolvare()
{
	int a,b,n,i=0;
	f>>n;
	do
	{
		f>>a>>b;
		g<<euclid(a,b)<<endl;
		i++;
	}while(i<n);
}

int main()
{

rezolvare();
return 0;

}