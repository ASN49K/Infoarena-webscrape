#include<iostream.h>
#include<fstream.h>
int n,a,b;
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
		while(a!=b)
			if(a>b) a=a-b;
		   else b=b-a;
		g<<a<<endl;
}
f.close();
g.close();
return 1;
}