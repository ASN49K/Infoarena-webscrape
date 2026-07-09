#include<cstdio>
#include<algorithm>
#define NMAX 1024
using namespace std;
int m,n,ma,a[NMAX],b[NMAX],d[NMAX][NMAX],sir[NMAX];
int main()
{freopen("cmlsc.in","rt",stdin);
 freopen("cmlsc.out","wt",stdout);
 scanf("%d%d",&m,&n);
 for(register int i=1;i<=m;i++) scanf("%d",&a[i]);
 for(register int j=1;j<=n;j++) scanf("%d",&b[j]);
 for(register int i=1;i<=m;i++)
	for(register int j=1;j<=n;j++) if(a[i]==b[j]) d[i][j] = max(max(d[i-1][j], d[i][j-1]),d[i-1][j-1]+1);
						else d[i][j]= max(d[i-1][j],d[i][j-1]);
 for(register int i=m,j=n;i;)
	if(a[i]==b[j]) {sir[++ma] = a[i]; j--;i--;}
	   else {if (d[i-1][j] < d[i][j-1]) j--; else i--;}
 printf("%d\n", ma);
 for (register int i = ma; i; --i) printf("%d ", sir[i]);
 return 0;
}
