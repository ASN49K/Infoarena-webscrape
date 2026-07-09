#include<fstream>
#include<iostream>
using namespace std;
int mat[1025][1025],n,m,k,i,j;
char a[1025],b[1025],sir[1025];
int maxim(int a,int b)
{
	if(a>b)
		return a;
	return b;
}

int main()
{
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	
	f>>n>>m;
	for(i=1;i<=n;i++)
		f>>a[i];
	for(j=1;j<=m;j++)
		f>>b[j];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			if(a[i]==b[j])
				mat[i][j]=mat[i-1][j-1] + 1;
			else
				mat[i][j]=maxim(mat[i-1][j],mat[i][j-1]);
		}
	
		/*
	cout<<"     ";
	for(i=1;i<=m;i++)
		cout<<b[i]<<" ";
	cout<<"\n\n";
	for(i=0;i<=n;i++)
	{
		if(i)
			cout<<a[i]<<"  ";
		else
			cout<<"   ";
		for(j=0;j<=m;j++)
			cout<<mat[i][j]<<" ";
		cout<<"\n";
	}
	*/
	
	g<<mat[n][m]<<'\n';
	k=0;
	for(i=n,j=m;i && j;)
	{
		if(a[i]==b[j])
		{
			sir[++k]=a[i];
			i--;
			j--;
		}
		else
		{
			if(mat[i][j-1]<mat[i-1][j])
				i--;
			else	
				j--;
		}
	}
	
	
	for(i=k;i;i--)
		g<<sir[i];
	
	
	f.close();
	g.close();
	return 0;
}
