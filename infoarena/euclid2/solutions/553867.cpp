#include<iostream.h>
#include<fstream.h>
long long n,t,y;

long long divi(long long r,long long a,long long b)
{
	if(r==0) return b;
	else return divi(a%b,b,r);
	
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
		f>>t>>y;
		g<<divi(t%y,t,y)<<endl;
    }
f.close();
g.close();
return 1;
}