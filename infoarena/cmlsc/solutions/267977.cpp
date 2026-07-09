/*
ID: masterw1
LANG: C++
TASK: subset
*/

#include<stdio.h>
#define N 400

int v[N], n;

void rezolvare()
{
	int k;
	scanf("%d",&n);
	v[0]=1;
	if(n*(n+1)%4)
	{
		printf("0\n");
		return;
	}
	k=(n+1)*n/4;
	
	for(int i=1;i<n;++i)
		for(int j=k-i;j>=0;--j)
			if(v[j])
				v[j+i]+=v[j];
	printf("%d\n",v[k]);
}

int main()
{
	freopen("subset.in","r",stdin);
	freopen("subset.out","w",stdout);
	
	rezolvare();
	
	return 0;
}
