#include<stdio.h>
#define nmax 1025
int a[nmax],b[nmax],din[nmax][nmax];
inline int max(int p, int q)
{
	if(p>q)
		return p;
	else
		return q;
}
int main()
{
	int i,j,k,n,l1,l2;

	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);

	scanf("%d %d",&l1,&l2);

	for(i=1;i<=l1;i++)
		scanf("%d",&a[i]);

	for(i=1;i<=l2;i++)
		scanf("%d",&b[i]);

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
	int ma;

	ma=din[l1][l2];

	k=1;

	for(i=1;i<=l1&&k<=ma;i++)
		for(j=1;j<=l2&&k<=ma;j++)
		{
			if(a[i]==b[j])
			{
				din[i][j]=din[i-1][j-1]+1;
				if(din[i][j]==k)
				{
					printf("%d ",a[i]);
					k++;
				}
			}
			else
				din[i][j]=max(din[i][j-1],din[i-1][j]);
		}


	return 0;

}
