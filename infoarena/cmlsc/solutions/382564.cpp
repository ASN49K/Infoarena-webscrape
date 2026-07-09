#include <fstream>
#include <iostream>
#include <iterator>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int a[1024];
int b[1024];

int lung[1024][1024];

int st[1024];
inline int max(int a,int b)
{
	return (a>b?a:b);

}

int main()
{
	int n,m;
	f>>n>>m;
	for(int i=1; i<=n; i++)
		f>>a[i];
	for(int i=1; i<=m; i++)
		f>>b[i];



	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			if(a[i]==b[j])
				lung[i][j]=lung[i-1][j-1]+1;
			else
				lung[i][j]=max(lung[i-1][j],lung[i][j-1]);

	int i,j;

	i=n;
	j=m;
	int poz_st=0;
	while(j>=1 && i>=1)
	{

		if(a[i]==b[j])
			st[poz_st++]=a[i];
		if(i>=1 && lung[i-1][j]==lung[i][j])
			i--;
		else
			j--;

	}
	for(int i=poz_st-1; i>=0; i--)
		g<<st[i]<<" ";
	return 0;
}
