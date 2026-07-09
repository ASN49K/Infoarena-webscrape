#include<stdio.h>
#define nmax 1030
unsigned char a[nmax],b[nmax],din1[nmax],din2[nmax];
inline int max(int p, int q)
{
	if(p>q)
		return p;
	else
		return q;
}
int main()
{
	int i,j,k=1,n,l1,l2;
	unsigned char vec[nmax];

	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);

	scanf("%d %d",&l1,&l2);

	for(i=1;i<=l1;i++)
		scanf("%d",&a[i]);

	for(i=1;i<=l2;i++)
		scanf("%d",&b[i]);

	for(i=1;i<=l1;i++)
	{	for(j=1;j<=l2;j++)
		{
			if(a[i]==b[j])
			{
				din1[j]=din2[j-1]+1;
				if(din1[j]==k)
				{
					k++;
					vec[k-1]=b[j];
				}
			}
			else
				din1[j]=max(din1[j-1],din2[j]);
		}
		for(j=1;j<=l2;j++)
			din2[j]=din1[j];
	}
	printf("%d\n",din1[l2]);
	for(i=1;i<k;i++)
		printf("%d ",vec[i]);

	return 0;

}
