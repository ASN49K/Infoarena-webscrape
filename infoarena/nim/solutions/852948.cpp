#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <cassert>
using namespace std;

#define PRO "nim"
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
		//freopen("test.out","w",stdout);
	}
}

#define MAX  1000001
#define INF 0xffffff

int a[MAX];

int main(int argv,char *args[])
{
	OpenFiles(argv==0);
	// start
	int t,n,sum=0,x;
		scanf("%d",&t);
		while(t--)
		{
			sum=0;
			scanf("%d",&n);
			while(n--)
			{
				scanf("%d",&x);
				sum^=x;
			}
			if(sum)printf("DA\n"); else printf("NU\n");
		}
	return 0;
}
