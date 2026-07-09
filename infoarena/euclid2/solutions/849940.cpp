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

#define PRO "euclid2"
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

#define MAX 13
#define INF 0xffffff

int Cmmdc(int x,int y)
{
	if(y==0)
	{
		return x;
	} else
		return Cmmdc(y,x%y);
}

int main(int argv,char *args[])
{
	OpenFiles(argv==0);
	// start
	int t,x,y;
		scanf("%d",&t);
		while(t--)
		{
			scanf("%d %d",&x,&y);
			printf("%d\n",Cmmdc(x,y));
		}
	return 0;
}
