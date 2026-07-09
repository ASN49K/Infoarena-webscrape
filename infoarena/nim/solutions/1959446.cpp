#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#define MaxN 20
using namespace std;

FILE*IN,*OUT;

int T,N,Val,X;
int main()
{
	IN=fopen("nim.in","r");
	OUT=fopen("nim.out","w");

	fscanf(IN,"%d",&T);
	for(int t=1;t<=T;t++)
	{
		fscanf(IN,"%d",&N);
		Val=0;
		for(int i=1;i<=N;i++)
			fscanf(IN,"%d",&X),Val^=X;
		if(Val==0)
			fprintf(OUT,"DA\n");
		else fprintf(OUT,"NU\n");
	}
	return 0;
}