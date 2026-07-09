
#include<stdio.h>
int a[100],b[100],s[100][100],m,n,i,j;
void citire()
{scanf("%d%d",&n,&m);
for(i=1;i<=n;i++)
	scanf("%d",&b[i]);
for(i=1;i<=m;i++)
	scanf("%d",&a[i]);}
void rez()
{int k=1;
	for(i=1;i<=m;i++)
	for(j=1;j<=n;j++)
		if(a[i]==b[j])
			s[i][j]=1+s[i-1][j-1];
		else 
			if(s[i-1][j]>s[i][j-1])
				s[i][j]=s[i-1][j];
			else s[i][j]=s[i][j-1];
	for(i=1;i<=m;i++)
	for(j=1;j<=n;j++)
		if(s[i][j]==k)
        { printf("%d ",b[j]);
        k++; i++; j++;}		
}

			
			
int main()
{ freopen("cmlsc.in","r",stdin);
  freopen("cmlsc.out","w",stdout);
citire();
rez();

return 0;}
	