#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

void citire();
void pd();

int a[202];
int b[202];
int n,m;
int lcs[202][202];
int op[202][202];

int main()
{
citire();
pd();

return 0;
}


void citire()
{
char s[202];	
int i;

fin>>s;
n=strlen(s);

for(i=0;i<n;i++)
	a[i+1]=s[i]-'0';

fin>>s;
m=strlen(s);

for(i=0;i<m;i++)
	b[i+1]=s[i]-'0';

}

void pd()
{
int i,j;

for(i=n;i>0;i--)
	{
	for(j=m;j>0;j--)
		{
		if(a[i]==b[j])
			{
			lcs[i][j]=1+lcs[i+1][j+1];
			op[i][j]=1;
			}
			else
			{	
			if(lcs[i+1][j]>lcs[i][j+1])
				lcs[i][j]=lcs[i+1][j],op[i][j]=2;
				else
				lcs[i][j]=lcs[i][j+1],op[i][j]=3;	
			}
		}
	}

i=1;j=1;

while(i<=n && j<=m)
	{
	if(op[i][j]==1)
		{
		fout<<a[i];
		i++; j++;
		}
		else
		if(op[i][j]==2)
		i++;
		else
		if(op[i][j]==3)
		j++;
	}
}