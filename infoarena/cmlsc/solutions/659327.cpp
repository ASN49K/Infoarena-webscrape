#include<cstdio>
#include<fstream>

using namespace std;

const int MaxN = 1025;
const char InFile[] = "cmlsc.in";
const char OutFile[] = "cmlsc.out";

int n,m,A[MaxN],B[MaxN],Din[MaxN][MaxN],sol[MaxN];

int maxim(int a, int b)
{
	return a > b ? a : b;
}
	
int main()
{
	freopen( InFile , "r" , stdin );
	freopen( OutFile , "w" , stdout );
	scanf("%d%d" , &m , &n );
	int i,j;
	for( i = 1 ; i <= m ; i++ )
		scanf("%d" , A+i);
	for( j = 1 ; j <= n ; j++ )
		scanf("%d" , B+j);
	for( i = 1 ; i <= m ; i++ )
		for( j = 1 ; j <= n ; j++ )
			if( A[i] == B[j] )
				Din[i][j] = Din[i-1][j-1] + 1;
				else
				Din[i][j] = maxim(Din[i-1][j],Din[i][j-1]);
	int lg = 0;
	for( i = m , j = n ; i ; )
		if( A[i] == B[j] )
			{
				sol[++lg] = A[i];
				--i;
				--j;
			}
			else
			if( Din[i-1][j] < Din[i][j-1] )
				--j;
				else
				--i;
	printf("%d\n" , lg);
	for( i = lg ; i ; --i )
		printf("%d " , sol[i] );
	return 0;
}
