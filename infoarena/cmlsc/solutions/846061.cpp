#include <stdio.h>
#include <algorithm>
using namespace std;
int a[1025],b[1025],bst[1025][1025];

void OpenFiles(int);
void Cmlsc(int,int,int*,int*,int [][1025]);
void Tipar(int,int);

int main(int arg,char *argv[])
{
	OpenFiles(arg);
		int n,m;
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=m;i++)scanf("%d",&b[i]);
		Cmlsc(n,m,a,b,bst);
		printf("%d\n",bst[n][m]);
		Tipar(n,m);
	return 0;
}

void Cmlsc(int n,int m,int *a,int *b,int bst[][1025])
{
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
		if(a[i]==b[j])bst[i][j]=1+bst[i-1][j-1]; else
		bst[i][j]=max(bst[i-1][j],bst[i][j-1]);
}

void Tipar(int i,int j)
{
	if(bst[i][j]==0)return; else
	{
		if(a[i]==b[j])
		{
			Tipar(i-1,j-1);
			printf("%d ",a[i]);
			return ;
		} else
		if(bst[i-1][j]>bst[i][j-1])
			Tipar(i-1,j); 
		else
			Tipar(i,j-1);
	}
}

void OpenFiles(int arg){
	freopen("cmlsc.in","r",stdin);
	if(arg==0)
	{
		freopen("cmlsc.out","w",stdout);
	}
}
