#include<iostream>
#include<stdio.h>
FILE *f=fopen("cmlsc.in","r"),*g=fopen("cmlsc.out","w");
int c[1030][1030],a[1030],b[1030];
void RoadToBeijingHaHaHa(int x,int y)
{
	if(!c[x][y]) return ;
	if(a[x]==b[y])
	{
		RoadToBeijingHaHaHa(x-1,y-1);
		fprintf(g,"%d ",a[x]);
	}
	else
		if(c[x-1][y]>c[x][y-1])
			RoadToBeijingHaHaHa(x-1,y);
		else
			RoadToBeijingHaHaHa(x,y-1);
}
int main()
{
	int i,j,m,n;
	fscanf(f,"%d%d",&m,&n);
	for(i=1;i<=m;i++)
		fscanf(f,"%d",&a[i]);
	for(i=1;i<=n;i++)
		fscanf(f,"%d",&b[i]);
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(a[i]==b[j])
				c[i][j]=c[i-1][j-1]+1;
			else
				if(c[i-1][j]>c[i][j-1])
					c[i][j]=c[i-1][j];
				else
					c[i][j]=c[i][j-1];
	fprintf(g,"%d\n",c[m][n]);
	RoadToBeijingHaHaHa(m,n);
	return 0;
}