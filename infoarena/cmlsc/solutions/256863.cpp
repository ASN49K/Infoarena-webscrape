#include <stdio.h>

unsigned short int S[1025][1025],A[1025],B[1025],sol[1025],k;

int main()
{
freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);

int n,m,i,j;
scanf("%d%d",&n,&m);
for (i=1;i<=n;i++) scanf("%hu",&A[i]);
for (i=1;i<=m;i++) scanf("%hu",&B[i]);

for (i=1;i<=n;i++)
for (j=1;j<=m;j++)
if (A[i]==B[j]) S[i][j]=S[i-1][j-1]+1;
else if (S[i-1][j]>S[i][j-1]) S[i][j] = S[i-1][j];
     else S[i][j] = S[i][j-1];

i=n;j=m;k=0;

while (S[i][j])
{
if (A[i]==B[j]) sol[++k]=A[i],i--,j--;
else if (S[i-1][j]>S[i][j-1]) i--;
     else j--;
}

printf("%d\n",S[n][m]);
while (k) printf("%hu ",sol[k--]);

}
