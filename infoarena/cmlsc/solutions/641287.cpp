#include<stdio.h>
int n,m,i,x[1030],y[1030],j,l[1030][1030],h,k;
int main()
{
	freopen("cmlsc6.in","r",stdin);
	freopen("cmlsc6.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
        scanf("%d",&x[i]);
	for(j=1;j<=m;j++)
		scanf("%d",&y[j]);//aici trebuia m nu n

	for(k=1;k<=n;k++)
		for(h=1;h<=m;h++) //idem
			if(x[k]==y[h])
				l[k][h]=1+l[k-1][h-1];
			else
				if(l[k-1][h]>l[k][h-1])
					l[k][h]=l[k-1][h];
				else
					l[k][h]=l[k][h-1];
	printf("%d\n",l[n][m]);
	int d[1030];//aici dimensionare proasta! ai pus d[100]
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
		return 0;
}


