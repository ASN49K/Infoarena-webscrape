#include<cstdio>
using namespace std;
int a,b,aux,i,r,n;
int main()
{
 freopen("euclid2.in","rt",stdin);
 freopen("euclid2.out","wt",stdout);
 scanf("%d",&n);
 for(i=1;i<=n;++i)
	{
	 scanf("%d%d",&a,&b);
	 if(a<b) {aux=a; a=b; b=aux;}
	 while(b){r=a%b; a=b; b=r;};
     printf("%d\n",a);
	 }
 return 0;
}
