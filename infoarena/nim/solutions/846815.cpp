#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <set>
using namespace std;
#define inf 0xffffff
#define Max 100001



int main()
{
	int n,m,x,s;
	freopen("nim.in","r",stdin);
	freopen("nim.out","w",stdout);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&m);
			s=0;
			for(int j=1;j<=m;j++)
				{
					scanf("%d",&x);
					s^=x;
				}
			if(s==0)printf("NU\n"); else printf("DA\n");
		}
	return 0;
}
