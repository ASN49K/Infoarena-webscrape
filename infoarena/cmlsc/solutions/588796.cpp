#include<fstream.h>
#include<stdio.h>
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025],b[1025];
int n,m,i,k;
int verif(int i,int c)
{	if (i>m) return 0;
	else 
		if (a[i]==c) return 1;
		else return verif(i+1,c);
}
int main(){
	FILE * stefi;
	stefi=fopen("cmlsc.in","r");
	fscanf(stefi,"%d%d",&m,&n);
	for (i=1;i<=m;i++) fscanf(stefi,"%d",&a[i]);
	for (i=1;i<=n;i++)
	{	fscanf(stefi,"%d",&b[i]);
		if (!verif(1,b[i])) { b[i]=0; k++; }
	}
	k=n-k;
	g<<k<<'\n';
	for (i=1;i<=n;i++)
		if (b[i]) g<<b[i]<<' ';
	f.close();
	g.close();
	return 0;	
}