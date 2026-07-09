#include<iostream>
#include<fstream>
using namespace std;
fstream f,g;
int a[100][100],b[100],c[100],n,m,z[100];
void citire(){
	f>>n;
	for(int i=1;i<=n;i++)
		f>>b[i];
	f>>m;
	for(int j=1;j<=m;j++)
		f>>c[j];
}
int maxim(int x,int y)
{
	if(x>y)
		return x;
	else return y;
}
void matrice()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(b[i]==c[j])
				a[i][j]=1+a[i-1][j-1];
			else 
				a[i][j]=maxim(a[i-1][j],a[i][j-1]);
}
void afis()
{
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++)
			g<<a[i][j]<<" ";
		g<<"\n";
	}
}
void solutie()
{
	int i=n,j=m,k=0;
	while(i>0 && j>0)
	{
		if(b[i]==c[j]){
			k++;
			z[k]=b[i];
			i--;
			j--;
		}
		else if(a[i][j]==a[i-1][j])
			i--;
		else
			j--;
	}
	f<<a[n][m]<<"\n";
	for(i=k;i>=1;i--)
		g<<z[i]<<" ";
}
	
int main(){
	f.open("cmlsc.in", ios::in);
    g.open("cmslc.out", ios::out);	
	citire();
	matrice();
	afis();
	solutie();
}