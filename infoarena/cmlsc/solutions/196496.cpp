#include <cstdio>
#define N_MAX 1<<10
#define IN  "cmlsc.in"
#define OUT "cmlsc.out"
#include <algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;++i)

using namespace std;
int n,m;
char s1[N_MAX],s2[N_MAX];
short int c[N_MAX][N_MAX],b[N_MAX][N_MAX];


int sir[1024];
void scan()
{
	freopen(IN, "r",stdin);
	freopen(OUT, "w",stdout);
	scanf("%d%d\n",&n,&m);
	FOR(i,1,n) 
		scanf("%d", &s1[i]);
	FOR(i,1,m)
		scanf("%d", &s2[i]);
}

void solve()
{
	FOR(i,1,n)
		FOR(j,1,m)
			if(s1[i]==s2[j])
				c[i][j] = c[i-1][j-1] +1,
				b[i][j] = 1;
			else
				if(c[i-1][j] >= c[i][j-1])
					c[i][j] = c[i-1][j],
					b[i][j] = 2;
				else
					c[i][j] = c[i][j-1],
					b[i][j] = 3;
	printf("%d\n", c[n][m]);				
}

void print(int i,int j)
{
	if(!i || !j)
		return;
	if(b[i][j]==1)
	{
		print(i-1,j-1);
		printf("%d ",s1[i]);
	}	
	else
		if(b[i][j]==2)
			print(i-1,j);
		else
			print(i,j-1);
}

int main()
{
	scan();
	solve();
	print(n,m);
	return 0;
}
