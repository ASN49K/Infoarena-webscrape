#include<cstdio>
#include<vector>
using namespace std;
inline int max(int a,int b)
{
	return a>b ? a : b;
}
vector < int >  d;
void backtrack( int **c,int *a,int *b,int i,int j)
{
	if(i==0||j==0) ;
	else 
		if(a[i]==b[j]) 
		{
			d.push_back(a[i]);
			 backtrack(c,a,b,i-1,j-1);
		}
		else 
			if(c[i-1][j]>c[i][j-1]) backtrack(c,a,b,i-1,j);
				else  backtrack(c,a,b,i,j-1);

}
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	int cont=0,n,m,*a,*b,aux,**c;

	scanf("%d %d",&n,&m);
	
	
	
	a=new int[n+1];
	b=new int[m+1];
	c=new int*[n+3];
	for (int i=0;i<=n+1;++i)
		c[i]=new int[m+2];

	for (int i=1;i<=n;++i)
	scanf("%d",&a[i]);

	

	for (int i=1;i<=m;++i)
	scanf("%d",&b[i]);

	c[0][0]=0;
	c[1][0]=0;
	c[0][1]=0;

	for(int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
		{
			
			if(a[i]==b[j])c[i][j]=c[i-1][j-1]+1;
				else 
					c[i][j]=max(c[i][j-1],c[i-1][j]);
		}

	
	backtrack(c,a,b,n,m)	;

	printf("%d\n",c[n][m]);
	for(int i=d.size()-1;i>=0;--i)
		

	printf("%d ",d[i]);


}


				