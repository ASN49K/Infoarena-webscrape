#include<iostream.h>
#include<fstream.h>
long long n,a,b;

long long divi(long long t,long long y)
{
	if(y==t) return y;
	else if(t>y) return divi(t-y,y);
	     else return divi(t,y-t);
}

int main()
{
	ifstream f;
	f.open("euclid2.in");
	ofstream g;
	g.open("euclid2.out");
	f>>n;
	for(int i=1;i<=n;i++)
	{   
		f>>a>>b;
		g<<divi(a,b)<<endl;
    }
f.close();
g.close();
return 1;
}