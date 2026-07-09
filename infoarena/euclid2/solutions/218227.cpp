#include"stdio.h"
int m(const int x){if(x<0)return -x;return x;}
void cmmdc(const int x,const int y)
{if(x%y==0){printf("%d\n",y);return;}else cmmdc(m(y-x),x);}
int main()
{int x,y,n;
freopen("euclid2.in","r",stdin);freopen("euclid2.out","w",stdout);
scanf("%d",&n);for(int loop=1;loop<=n;loop++){scanf("%d%d",&x,&y);cmmdc(x,y);}
return 0;
}
