#include <cstdio>
using namespace std;

int n,m;
int a[1024],b[1024],sol[1024];
int mat[1024][1024];

int max(int x,int y);

int main(){
	int i,j;
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&n,&m);
	
	for(i=0;i<n;++i) scanf("%d",&a[i]);
	for(i=0;i<m;++i) scanf("%d",&b[i]);
	
	for(i=0;i<n;++i)
		for(j=0;j<m;++j)
			if (a[i]==b[j]) 
				if (!j)
					mat[i][j]=1;
				else 	
					mat[i][j]=mat[i-1][j-1]+1;
			else 
				if (!i&&!j) 
					mat[i][j]=0;
				else if (!i) 
					mat[i][j]=mat[i][j-1];
				else if (!j) 
					mat[i][j]=mat[i-1][j];
				else 
					mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
	
	i=n-1;j=m-1;
	while (i+1&&j+1){
		while (mat[i][j]==mat[i-1][j]) --i;
		while (mat[i][j]==mat[i][j-1]) --j;
		sol[++sol[0]]=a[i];
		i-=1024>>10;
		j-=1024>>10;
		}
	
	printf("%d\n",sol[0]);
	for(i=sol[0];i>0;--i) printf("%d ",sol[i]);
	printf("\n");
	
	return 0;
}

int max(int x,int y){
	if (x>y) return x;
	else return y;
}
