#include<algorithm>
#include<stdio.h>
#define maxn 1025
using namespace std;
int a[maxn],b[maxn],n,m,lg[maxn][maxn],vec[maxn],nr;
void read(){
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
}
void cmlsc(){
	int i,j;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(a[i]==b[j])
				lg[i][j]=1+lg[i-1][j-1];
			else
				lg[i][j]=max(lg[i-1][j],lg[i][j-1]);
	for(i=m,j=n;i;){
		if(a[i]==b[j])
			vec[++nr]=a[i],i--,j--;
		else
			if(lg[i-1][j]<lg[i][j-1])
				j--;
			else
				i--;
	}
	printf("%d\n",nr);
	for(i=nr;i>=1;i--)
		printf("%d ",vec[i]);
}
int main (){
	read();
	cmlsc();
	return 0;}