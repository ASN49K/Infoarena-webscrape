#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;
#define maxn 1025
stack <int> Q;
int a[maxn],b[maxn],c[maxn][maxn],na,nb,maxi;
int main(){
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&na,&nb);
	for(int i=1;i<=na;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=nb;++i)
		scanf("%d",&b[i]);
	if(a[1]==b[1])
		c[1][1]=1;
	for(int i=2;i<=na;++i)
		if(a[i]==b[0])
			c[0][i]=1;
		else
			c[0][i]=c[0][i-1];
	for(int i=2;i<=nb;++i)
		if(a[0]==b[i])
			c[i][0]=1;
		else
			c[i][0]=c[i-1][0];
	for (int i=1;i<=nb;++i)
		for(int j=1;j<=na;++j)
			if(b[i]==a[j]){
				c[i][j]=c[i-1][j-1]+1;
				if(c[i][j]>maxi)
					maxi=c[i][j];
			}
			else
				c[i][j]=max(c[i-1][j],c[i][j-1]);
	for(int i=1;i<=nb;++i){
		for(int j=1;j<=na;++j)
			printf("%d ",c[i][j]);
		printf("\n");
	}
	printf("%d\n",maxi);
	int i=nb,j=na;
	while(i>=1 && j>=1)
		if(b[i]==a[j])	{
		Q.push(a[j]),--i,--j;
		}
		else
			if(i-1>=1 && c[i-1][j]==c[i][j])
				--i;
			else
				--j;
	while(!Q.empty()){
		printf("%d ",Q.top() );
		Q.pop();
	}
	return 0;
}