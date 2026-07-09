#include <cstdio>

using namespace std;

#define Nmax 1025
#define FIN "cmlsc.in"
#define FOUT "cmlsc.out"

int d[Nmax][Nmax];
int a[Nmax],b[Nmax];
int sir[Nmax];
int lmax,n,m;

inline int max(int a, int b)
{
	if (a>b) return a;
	return b;
}

void citire()
{
	int i,j;
	
	freopen(FIN,"r",stdin);
	freopen(FOUT,"w",stdout);
	
	scanf("%d %d", &n,&m);
	for (i=1;i<=n;++i)
		 scanf("%d", &a[i]);
	for (i=1;i<=m;++i)
		 scanf("%d", &b[i]);
}

void solve()
{
	int i,j;
	for (i=1;i<=n;++i)
		 for (j=1;j<=m;++j)
			  if (a[i]==b[j])
				   d[i][j]=d[i-1][j-1]+1;
			       else
				   d[i][j]=max(d[i-1][j],d[i][j-1]);

	for (i=n,j=m;i,j;)
         if (a[i]==b[j])
         {
 			sir[++lmax]=a[i];
			i--;
			j--;
		 }
		 else
		 if (d[i-1][j]>d[i][j-1])
         {
			i--;
		 }
		 else
		 {
			j--;
		 }
}

void scrie()
{
	int i,j;
	printf("%d\n",lmax);
	for (i=lmax;i>=1;--i)
		 printf("%d ", sir[i]);
}

int main()
{
	citire();
	solve();
	scrie();
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
		 
	