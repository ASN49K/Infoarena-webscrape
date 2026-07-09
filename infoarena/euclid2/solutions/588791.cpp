#include<fstream.h>
#include<stdio.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,n,i;
int euclid(int a,int b)
{	int r;
	r=a%b;
	while (r)
	{	a=b;
		b=r;
		r=a%b;
	}
	return b;
}
int main(){
	FILE * stefi;
	stefi=fopen("euclid2.in","r");
	fscanf(stefi,"%d",&n);
	for (i=1;i<=n;i++)
	{	fscanf(stefi,"%d%d",&a,&b);
		g<<euclid(a,b)<<'\n';
	}		
	f.close();
	g.close();
	return 0;
}