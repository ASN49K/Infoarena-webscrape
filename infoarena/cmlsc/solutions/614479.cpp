#include<stdio.h>
#include<iostream>
using namespace std;
int m,n,a[1050],b[1030],l[1030][1030];
void subsir()
{
	int i,j;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(a[i]==b[j])
				l[i][j]=l[i-1][j-1]+1;
			else
				if(l[i-1][j]>=l[i][j-1])
					l[i][j]=l[i-1][j];
				else l[i][j]=l[i][j-1];
}
int main()
{
freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);
scanf("%d %d",&m,&n);
int i,j;
for(i=1;i<=m;i++)
	scanf("%d",&a[i]);
for(i=1;i<=n;i++)
	scanf("%d",&b[i]);
subsir();
printf("%d\n",l[m][n]);
int d,s[1030];
d=l[m][n];
i=m;j=n;
while(d>0)
{
	if(a[i]==b[j])
	{
		s[d]=a[i];
	d--;
	i--;
	j--;
	}
	else
	if(l[i-1][j]==l[i][j])
		i--;
	else
	j--;
}
for(i=1;i<=l[m][n];i++)
printf("%d ",s[i]);
return 0;
}
