#include<fstream>

const int N=1025;

char sol[N][N],x[N],y[N];
int a[N][N],n,m;

void drum(int i,int j)
{
	if(a[i][j])
	{
		if(sol[i][j]==3)
			{	
				drum(i-1,j-1);
				printf("%d ",x[i]);
			}
		else
			if(sol[i][j]==1)
				drum(i,j-1);
			else
				drum(i-1,j);
	}
}

int main()
{
 	freopen("cmlsc.in","r",stdin);
 	freopen("cmlsc.out","w",stdout);

		scanf("%d%d",&n,&m);

		int i,j,r;
			
			for(i=1;i<=n;++i)
				scanf("%d",&r),x[i]=r;

			for(i=1;i<=m;++i)
				scanf("%d",&r),y[i]=r;

			for(i=1;i<=n;++i)
				for(j=1;j<=m;++j)
					if(x[i]==y[j])
					{
						a[i][j]=a[i-1][j-1]+1;
						sol[i][j]=3;
					}
					else
						if(a[i][j-1]>a[i-1][j])
						{
							a[i][j]=a[i][j-1];
							sol[i][j]=1;
						}
						else
						{
							a[i][j]=a[i-1][j];
							sol[i][j]=2;
						}
	 
			printf("%d\n",a[n][m]);

			drum(n,m);


	return 0;
}

