#include<iostream>
#include<fstream>
#define max 1025
using namespace std;
fstream f("cmlsc.in",ios::in), g("cmlsc.out",ios::out);
int x[max],y[max],mat[max][max],n,m;
void citire(int v[max],int lv);
void prelucrare();
int main()
{
	int i,j,z;
	f>>n>>m;
	citire(x,n);
	citire(y,m);
	prelucrare();
	z=mat[1][1];i=j=1;
	while(z)
		if(z==mat[i+1][j])
			i++;
		else
			if(z==mat[i][j+1])
				j++;
			else
			{	z--;cout<<y[j]<<" ";g<<y[j]<<" ";}	
	return 0;
}
void citire(int v[max],int lv)
{
	int i;
	for(i=1;i<=lv;i++)
		f>>v[i];
}
void prelucrare()
{
	int i,j;
	for(i=n;i>=1;i--)
		for(j=m;j>=1;j--)
			if(x[i]==y[j])
				mat[i][j]=1+mat[i+1][j+1];
			else
				if(mat[i][j+1]>mat[i+1][j])
					mat[i][j]=mat[i][j+1];
				else
					mat[i][j]=mat[i+1][j];
}