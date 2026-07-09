#include <fstream>
#define DMAX 1000

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m;
int a[DMAX], b[DMAX];
int LCS[DMAX][DMAX];

void citire(), pd(), afisare();

int main()
{
citire();
pd();
afisare();
return 0;
}

void citire()
{
int i, j;
fin>>n>>m;
for (i=1; i<=n; i++) fin>>a[i];
for (j=1; j<=m; j++) fin>>b[j];
}

void pd()
{
int i, j;

for (i=n; i>0; i--)
	for (j=m; j>0; j--)
		{
			if (a[i]==b[j])
				LCS[i][j]=1+LCS[i+1][j+1];
				else
				if (LCS[i][j+1]>LCS[i+1][j])
					LCS[i][j]=LCS[i][j+1];
					else
					LCS[i][j]=LCS[i+1][j];
		}
}

void afisare()
{
int i, j;

fout<<LCS[1][1]<<'\n';
for (i=1, j=1; i<=n && j<=m; )
	{
		if (a[i]==b[j]) {fout<<a[i]<<' '; i++; j++;}
			else
			if (LCS[i][j]==LCS[i+1][j]) i++;
				else
				j++;
	}
fout<<"\n";
fout.close();
}
