#include<cstdio>
#include<vector>

#define N 1028
#define max(a,b) ((a>b) ? a:b)
#define min(a,b) ((a<b) ? a:b)

using namespace std;

int m,n, A[N],B[N],D[N][N];

vector <int> S;

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	
    scanf("%d %d",&n,&m);
	int i,j;
    for(i=1;i<=n;++i)
        scanf("%d",&A[i]);
	for(i=1;i<=m;++i)
        scanf("%d",&B[i]);
 
    for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
		{
			if(A[i]==B[j])
				D[i][j]=1+D[i-1][j-1];
			else
				D[i][j]=max(D[i][j-1],D[i-1][j]);
		}
	
	for(i=n, j=m; i>0; )
	{
		if(A[i]==B[j])
		{
			S.push_back(A[i]);
			--i, --j;
		}
		else if(D[i-1][j]<D[i][j-1])
			--j;
		else --i;
	}
	
	printf("%d\n",S.size());
	for(i=S.size()-1 ; i>=0 ; --i)
		printf("%d ",S[i]);
		
    return 0;
}