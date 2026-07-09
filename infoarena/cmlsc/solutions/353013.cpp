#include<fstream>
using namespace std;

int c[1025][1025];


void afis(int i, int j,int a[1025],int b[1025])
 {
	 if(c[i][j])
	 {
		if(a[i]==b[j]) { printf("%d ",a[i]); afis(--i,--j,a,b); }
		  else if(c[i][j-1]>c[i-1][j]) afis(i,--j,a,b);
		                      else afis (--i,j,a,b);
	 }
		   
}
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	
	int n,m,a[1025],b[1025],i,j,max=0,maxi,maxj;
	
	scanf("%d%d",&m,&n);
	for(i=1; i<=m; i++) scanf("%d",&a[i]);
	for(i=1; i<=n; i++) scanf("%d",&b[i]);
	
	for(i=1; i<=m; i++)
		for(j=1; j<=n; j++)
			if( a[i]==b[j] ) 
			{
				c[i][j]=c[i-1][j-1]+1;
				if(c[i][j]>max) { max=c[i][j]; maxi=i; maxj=j; }
			}
			else
			{
				if(c[i-1][j]>=c[i][j-1])
					c[i][j]=c[i-1][j];
				else c[i][j]=c[i][j-1];
			}
			
	printf("%d\n",max);
	
	afis(m,n,a,b);
	
	
	
}
	
	
