#include <cstdio>

#define file_in "cmlsc.in"
#define file_out "cmlsc.out"

#define Nmax 1030

int n,m,i,j;
int a[Nmax];
int b[Nmax];
int d[Nmax][Nmax];
int lmax,sir[Nmax];

inline int max(int a, int b) { return a>b?a:b; } 

int main()
{
	freopen(file_in,"r",stdin);
	freopen(file_out,"w",stdout);
	
	scanf("%d %d", &n, &m);
	for (i=1;i<=n;++i)
		 scanf("%d", &a[i]);
	for (i=1;i<=m;++i)
		 scanf("%d", &b[i]);
	
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
		 if (d[i][j-1]>d[i-1][j])
		 	j--; 
		 else
            i--;

	printf("%d\n", lmax);
	for (i=lmax;i>=1;--i)
		 printf("%d ", sir[i]);
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
	
}
