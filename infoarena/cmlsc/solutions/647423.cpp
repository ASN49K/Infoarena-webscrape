#include<iostream>
#include<fstream>
using namespace std;
int x[1025],y[1025],m,n,lcs[1025][1025],i,j,lala[1025];
void asd()
{
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(x[i]==y[j])
				lcs[i][j]=lcs[i-1][j-1]+1;
			else lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
			i=0;
} 
void afiseaza( int a, int b)
{	ofstream fout("cmlsc.out");
	if(lcs[a][b])
	{
		if(x[a]==y[b]) 
		{	lala[lcs[n][m]-i]=x[a];
			i++;
			afiseaza(a-1,b-1);
		}
		else {
			if(lcs[a][b-1]==lcs[a][b])
			afiseaza(a,b-1);
		
			else 
				if (lcs[a-1][b]==lcs[a][b]) 
				afiseaza(a-1,b);
			} 
		for(i=1;i<=lcs[n][m];i++)
		fout<<lala[i]<<" ";
	}
	else fout<<"0";
	fout.close();
}
	int main()
{	ifstream fin("cmlsc.in");
	fin>>n>>m;
	for(i=1;i<=n;i++)
		fin>>x[i];
	for(i=1;i<=n;i++)
	fin>>y[i];
	asd();
	afiseaza(n,m);
	fin.close();
	return 0;
}