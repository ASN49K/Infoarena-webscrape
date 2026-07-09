#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <cassert>
using namespace std;

#define PRO "cmlsc"
void OpenFiles(int EVAL)
{
	if(EVAL)
	{
		char input[100] = PRO, output[100] = PRO;
		freopen(strcat(input, ".in"),"r",stdin);
		freopen(strcat(output,".out"),"w",stdout);
	} else
	{
		freopen("test.in","r",stdin);
		freopen("test.out","w",stdout);
	}
}

#define MAX 1026
#define INF 0xffffff

int bst[MAX][MAX],a[MAX],b[MAX],n,m;

void Cmlsc()
{
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
		if(a[i]==b[j])
			bst[i][j] = 1 + bst[i-1][j-1]; else
			bst[i][j] = max(bst[i-1][j], bst[i][j-1]);
}

void Tipar(int n,int m)
{
	if(bst[n][m]>0)
	{
		if(a[n]==b[m])
		{
			Tipar(n-1,m-1);
			printf("%d ",a[n]);
		} else
		if(bst[n-1][m] > bst[n][m-1])
			Tipar(n-1,m); else
			Tipar(n,m-1);
	}
}

int main(int argv,char *args[])
{
	OpenFiles(argv==0);
	// start
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=m;i++)scanf("%d",&b[i]);
		Cmlsc();
		printf("%d\n",bst[n][m]);
		Tipar(n,m);
	return 0;
}
