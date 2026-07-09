#include<stdio.h>
#include<string.h>
#define nmax 1100

int a[nmax],b[nmax];
int val[nmax];
int i,j,k,n,l1,l2,v=0;

inline int max(int p, int q)
{
	if(p>q)
		return p;
	else
		return q;
}
int main()
{
	int din[nmax][nmax];

	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);

	scanf("%d %d",&l1,&l2);

    memset(din,0,sizeof(din));

	for(i=1;i<=l1;i++)
		scanf("%d",&a[i]);

	for(i=1;i<=l2;i++)
		scanf("%d",&b[i]);

	k=1;

	for(i=1;i<=l1;i++)
		for(j=1;j<=l2;j++)
		{
			if(a[i]==b[j])
			{
				din[i][j]=din[i-1][j-1]+1;

			}
			else
				din[i][j]=max(din[i][j-1],din[i-1][j]);
		}
	printf("%d\n",din[l1][l2]);

	i=l1;
	j=l2;

	k=0;

	while(i>0&&j>0)
	{
		if(a[i]==b[j])
		{
			val[++k]=a[i];
			i--;
			j--;
		}
		else
		{
			if(din[i][j-1]>din[i-1][j])
				j--;
			else
				i--;
		}
	}
	for(i=k;i>0;i--)
		printf("%d ",val[i]);


	return 0;

}
