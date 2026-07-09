#include<stdio.h>
#define max(a,b) ((a>b)?a:b)

int m,n,a[100],b[100];
int suff[100][100],lcs[100][100];
int i,j,c[100],k;

int main(){
freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);

scanf("%d %d",&m,&n);

for(;i<m;i++)
	scanf("%d",&a[i]);
for(i=1;i<=n;i++)
	scanf("%d",&b[i]);

for(i=1;i<=m;i++)
	for(j=1;j<=n;j++)
		{
        if(a[i]==b[j])
            suff[i][j]=1+suff[i-1][j-1];
        else
            suff[i][j]=max(suff[i][j-1],suff[i-1][j]);
        }
        
for(i=m,j=n;i;)
    {
    if(a[i]==b[j])
        c[++k]=a[i],i--,j--;
    else if(suff[i-1][j]<suff[i][j-1])
        j--;
    else
        i--;
    }

printf("%d\n",k);

for(i=k;i;i--)
    printf("%d ",c[i]);
return 0;
}
