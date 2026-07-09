#include<fstream>
using namespace std;
const int N=1050;
unsigned  char sol[N][N],x[N],y[N];
int a[N][N],n,m;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
void drum(int i,int j)
{int r;
	if(a[i][j])
	{
		if(sol[i][j]==3)
			{r=x[i];	
				drum(i-1,j-1);
			f>>r;
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
 	

		f>>n>>m;

		int i,j,r;
			
			for(i=1;i<=n;++i)
				f>>x[i];

			for(i=1;i<=m;++i)
				f>>y[i];

			for(i=1;i<=n;++i)
				for(j=1;j<=m;++j)
					if(x[i]==y[j])
					{
						a[i][j]=a[i-1][j-1]+1;
						sol[i][j]=3;
					}
					else
						                                   
						{
							a[i][j]=a[i-1][j];
							sol[i][j]=2;
						}
	 
		g<<a[n][m];
        drum(n,m);
			


	return 0;
}
