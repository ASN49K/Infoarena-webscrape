#include <fstream>
#define NMAX 10002

using namespace std;

ifstream in("lcs.in");
ofstream o("lcs.out");

int a[NMAX],b[NMAX];
int n,m;
int lcs[NMAX][NMAX];

void cit()
{
int i;
in>>n>>m;
for(i=1;i<=n;i++)in>>a[i];
for(i=1;i<=m;i++)in>>b[i];
}

void pd()
{
int i,j;
for(i=n;i>0;i--)
	for(j=m;j>0;j--)
	{
	if(a[i]==b[j])
		lcs[i][j]=1+lcs[i+1][j+1];
	else
		{
		if(lcs[i][j+1]>lcs[i+1][j])
			lcs[i][j]=lcs[i][j+1];
		else
			lcs[i][j]=lcs[i+1][j];
		}
	}
}

void afis()
{
o<<lcs[1][1]<<endl;
int i,j;
i=j=1;
while(i<=n&&j<=m)
	{
	if(a[i]==b[j])o<<a[i]<<' ',i++,j++;
	else
		if(lcs[i][j]==lcs[i+1][j])i++;
		else j++;
	}
}

int main()
{
	cit();
	pd();
	afis();
	return 0;
}
