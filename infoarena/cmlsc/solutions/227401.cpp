#include<stdio.h>
int a[1025];
int b[1025];
int n,m;
int common[1024];
int din[1025][1025];
int max(int k1, int k2) {if(k1>k2) return k1; return k2;}
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d",&n,&m);
	{
		int i = 1;
		while( i<=n)
		{
			scanf("%d",&a[i]);
			 i++;
		}
	}
	
	{
		int i = 1;
		while( i<=m)
		{
			scanf("%d",&b[i]);
			 i++;
		}
	}
	
	{
		int i = 1;
		while( i<=n)
		{
			{
				int j = 1;
				while( j<=m)
				{
					{
						if(a[i]==b[j])
							din[i][j] = din[i-1][j-1] + 1;
						else
						din[i][j] = max(din[i-1][j],din[i][j-1]);
						}
					 j++;
				}
			}

			 i++;
		}
	}

	{
		int i=n,j=m;
		while(i!=0 && j!=0)
		{
			{
				if(a[i] == b[j])
					{
						common[++common[0]] = a[i];
						i--;
						j--;
						}
				else
				if(din[i-1][j] > din[i][j-1])
					i--;
				else
				j--;
				
				}
			;
		}
	}

	printf("%d \n", din[n][m]);
	{
		int i = common[0];
		while( i > 0)
		{
			printf("%d ",common[i]);
			 i--;
		}
	}
	
	return 0;
	}


