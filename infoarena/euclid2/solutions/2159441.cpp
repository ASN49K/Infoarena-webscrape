#include<iostream>
#include<fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int euclid(int a,int b)
{
	if(!b)
		return a;
	return euclid(b, a%b);
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