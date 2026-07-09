#include <fstream>
#define maxim(x, y) ((x > y) ? x : y)

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m;
int lcs[1025][1025], op[1025][1025];
int a[1025], b[1025];

void citire();
void pd();
void afisare();

int main()
{
	citire();
	pd();
	afisare();
	fout.close();
	return 0;
}

void citire()
{
	int i;
	fin>>n>>m;
	for(i=0; i<n; i++)
		fin>>a[i];
	for(i=0; i<m; i++)
		fin>>b[i];
}


void pd()
{
	int i, j;
	for(i=n-1;i>=0;i--)
		for(j=m-1;j>=0;j--)
			if(a[i]==b[j])
			{
				lcs[i][j]=lcs[i+1][j+1]+1;
				op[i][j]=1;
			}
			else
			{
				lcs[i][j]= maxim(lcs[i+1][j],lcs[i][j+1]);
			
				if(lcs[i+1][j]<lcs[i][j+1])
					op[i][j]=3;
				
				if(lcs[i+1][j]>=lcs[i][j+1])
					op[i][j]=2;
			}
}

void afisare()
{
	int i,j;
	i=j=0;
	fout<<lcs[i][j]<<'\n';
	
	while(i<n&&j<m)
		if(op[i][j]==1)
		{
			fout<<a[i]<<' ';
			i++; j++;
		}
		else
		{
			if(op[i][j]==3)
				j++;
			if(op[i][j]==2)
				i++;
		}
	
}
