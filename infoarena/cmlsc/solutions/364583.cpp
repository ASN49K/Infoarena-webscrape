#include<fstream>
#include<iostream>
using  namespace std;
const int MAXN = 1<<10+1;
int cml[MAXN][MAXN];
int a[MAXN] , b[MAXN],rez[MAXN];
int main()
{
	freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
	int n,m;
	scanf("%d %d",&n, &m);
	for(int i=0; i<n; i++)
	{
	    scanf("%d",a+i);
	    cml[i][0] = 0;
	}
	for(int i=0; i<m; i++)
	{
	    scanf("%d",b+i);
	    cml[0][i] = 0;
	}
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if( a[i] == b[j] ) cml[i+1][j+1] = cml[i][j] + 1;
            else cml[i+1][j+1] = max(cml[i][j+1] , cml[i+1][j]);
    int len = cml[n][m]-1 , i=n, j=m;
    int rez[len];
    printf("%d\n",len+1);
    for( ; len >= 0 ;)
    {
        if( a[i-1] == b[j-1] ) { rez[len--] = a[--i]; j--; }
        else if( cml[i-1][j] > cml[i][j-1] ) --i;
        else --j;
    }
    for(len = 0; len<cml[n][m]; len++)
        printf("%d ",rez[len]);
    printf("\n");
	return 0;
}
