#include <stdio.h>
int n,i,j,m,x[1025],y[1025],a[1025][1025];
void afis(int i,int j)
{
	if (a[i][j]>0)
	 {
		if (x[i]==y[j])
		       {
			afis (i-1,j-1);
			printf("%d ",x[i]);
		       }
		else
		if (a[i][j]==a[i-1][j])
			afis(i-1,j);
		else
			afis(i,j-1);
	}

}


int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&x[i]);
	for(j=1;j<=m;j++)
		scanf("%d",&y[j]);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		    if(x[i]==y[j])
			a[i][j]=a[i-1][j-1]+1;
		    else
		    if(a[i-1][j]>a[i][j-1])
			a[i][j]=a[i-1][j];
		    else
			a[i][j]=a[i][j-1];
	printf("%d\n",a[n][m]);
	i=n;
        j=m;
	/*while(a[i][j]!=0)
	{
		if(x[i]==y[j]){
			printf("%d ",x[i]);
			i--;
			j--;
		}
		else
		if(a[i][j]==a[i-1][j])
			i--;
			else
			j--;
	}*/
	afis(n,m);
	return 0;
}
