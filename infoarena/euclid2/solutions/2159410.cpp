#include<iostream>
#include<fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
int n,a,b,i=0;
f>>n;
do
{
	f>>a>>b;
	while(a!=b)
	{
		if(a>b)
			a=a-b;
		else
			b=b-a;
	}

	g<<a<<endl;
	i++;

}while(i<n);

return 0;

}