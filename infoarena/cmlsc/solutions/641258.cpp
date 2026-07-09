#include<stdio.h>
int n,m,i,x[1024],y[1024],j,l[1024][1024],h,k;
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&x[i]);
	for(j=1;j<=n;j++)
		scanf("%d",&y[j]);
	for(k=1;k<=n;k++)
		for(h=1;h<=n;h++)
			if(x[k]==y[h])
				l[k][h]=1+l[k-1][h-1];
			else
				if(l[k-1][h]>l[k][h-1])
					l[k][h]=l[k-1][h];
				else
					l[k][h]=l[k][h-1];
	printf("%d\n",l[n][m]);
	int d[100];
	for(i=0,k=n,h=m;l[k][h]; )
		if(x[k]==y[h])
		{
			d[i++]=x[k];
			k--;
			h--;
		}
		else
			if(l[k][h]==l[k-1][h])
				k--;
			else
				h--;
	for(k=i-1;k>=0;k--)
		printf("%d ",d[k]);
}


