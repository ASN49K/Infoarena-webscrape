#include<iostream.h>
#include<fstream.h>
int n,t,y;

int divi(int a,int b)
{
	if(a%b==0) return b;
	else return divi(b,a%b);
	
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
		g<<divi(t,y)<<'\n';
    }  
f.close();
g.close();
return 0;
}