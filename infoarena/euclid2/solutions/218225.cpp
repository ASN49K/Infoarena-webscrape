#include"stdio.h"
void cmmdc(const int x,const int y)
{if(x<0)x=-x;if(x%y==0){printf("%d\n",y);return;}else cmmdc(y-x,x);}
int main()
{int x,y,n;
freopen("euclid2.in","r",stdin);freopen("euclid2.out","w",stdout);
scanf("%d",&n);for(int loop=1;loop<=n;loop++){scanf("%d%d",&x,&y);cmmdc(x,y);}
return 0;
}
