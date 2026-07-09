#include<stdio.h>

int A[1050],B[1050],vec[1050][1050];
int m,n;
int max(int x,int y)
{
	if(x>y) return x;
	else return y;
}

void citire()
{
	freopen("cmlsc.in","r",stdin);
	scanf("%d %d",&n,&m);
	for(int i=n;i>=1;i--) 
		scanf("%d",&A[i]);
	for(int i=m;i>=1;i--)
	     scanf("%d",&B[i]);
}
void lungime(int A[],int B[],int n,int m)
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		if(A[i]==B[j]) vec[i][j]=vec[i-1][j-1]+1;
		else vec[i][j]=max(vec[i-1][j],vec[i][j-1]);
		
}

void afisare()
{
	freopen("cmlsc.out","w",stdout);
	printf("%d",vec[n][m]);
	int nr=vec[n][m];
	int i=n,j=m;
for(i=n,j=m;i;)
{
		
			if(A[i]==B[j]) printf("%d",A[i]),i--,j--;
			else if(vec[i][j-1]<vec[i-1][j]) i--;
			else j--;
	}
}

int main()
{
	
	citire();
	lungime(A,B,n,m);
	afisare();
}