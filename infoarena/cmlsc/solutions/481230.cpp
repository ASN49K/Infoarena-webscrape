#include <stdio.h>
#define MAX(a,b) (a>b) ? a : b


int m,n,count=0;
unsigned char a[1025],b[1025],c[1025][1025],ered[1025];


void lcs(){
int i,j;

for(i=1;i<=m;i++){

	for(j=1;j<=n;j++){
		if(a[i]==b[j]){c[i][j]=c[i-1][j-1]+1;}else{
		c[i][j]=MAX(c[i][j-1],c[i-1][j]);
		}

	}
}


}


void backtrace(int i,int j){

	if((i==0) || (j==0)){}
	else if(a[i]==b[j]){count++;ered[count]=a[i];backtrace(i-1,j-1);}
	else if(c[i][j-1]>c[i-1][j]){backtrace(i,j-1);}
	else{backtrace(i-1,j);}


}


int main(){
freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);
int i;
scanf("%d %d",&m,&n);
for(i=1;i<=m;i++){scanf("%d",&a[i]);}
for(i=1;i<=n;i++){scanf("%d",&b[i]);}

lcs();

backtrace(m,n);


printf("%d\n",c[m][n]);
for(i=c[m][n];i>=1;i--)
{printf("%d ",ered[i]);}


	return 0;}