#include<stdio.h>

int n,m,i,j,c[100][100],x[100],y[100],s[100];

void read()
{
scanf("%d%d",&n,&m);
for(i=0;i<n;i++)
   scanf("%d",&x[i]);

for(i=0;i<n;i++)
   scanf("%d",&y[i]);

}

void rez()
{
for(i=1;i<=n;i++)
   for(j=1;j<=m;j++)
	  {
	  if(x[i-1]==y[j-1])
		c[i][j]=c[i-1][j-1]+1;
	  else
		{
		if(c[i-1][j]>=c[i][j-1])
		   c[i][j]=c[i-1][j];
		else
		   c[i][j]=c[i][j-1];
		}
	  }
}

void sol()
{
int k;
k=0;
i=n;
j=m;
while(i>=0 && j>=0)
	  {
	  if(x[i-1]==y[j-1])
		{
		s[k++]=x[i-1];
		i--;
		j--;
		}
	  else
		{
		if(c[i-1][j]>c[i][j-1])
		  i--;
		else
		  j--;
		}
	  }
}

int main()
{
freopen("f.in","r",stdin);
freopen("f.out","w",stdout);

read();
rez();
sol();

printf("%d\n",c[n][m]);

for(i=c[n][m]-1;i>=0;i--)
	printf("%d ",s[i]);

printf("\n");

fcloseall();
return 0;
}