#include<fstream.h>
#include<stdio.h>
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025],b[1025],poz[1025];
int n,m,i,k,max;
int verif(int i,int c)
{	if (i>m) return 0;
	else 
		if (a[i]==c) return i;
		else return verif(i+1,c);
}
int main(){
	FILE * stefi;
	stefi=fopen("cmlsc.in","r");
	fscanf(stefi,"%d%d",&m,&n);
	for (i=1;i<=m;i++) fscanf(stefi,"%d",&a[i]);
	k=1;
	for (i=1;i<=n;i++)
	{	fscanf(stefi,"%d",&b[i]);
		poz[k++]=verif(1,b[i]);
		if (!poz[k-1]) { b[i]=0; k--; }
	}
	n=max=1;
	for (i=1;i<k;i++)
	{	if (poz[i]<poz[i+1]) n++;
		else 
			if (n>max) { max=n; m=i; n=1; } 
	}
	g<<max<<'\n';
	for (i=m-max+1;i<=m;i++)
		g<<a[poz[i]]<<' ';
	f.close();
	g.close();
	return 0;	
}