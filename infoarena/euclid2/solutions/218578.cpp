#include"stdio.h"  
void cmmdc(int x,int y)  
{  
if(x%y==0){printf("%d\n",y);}else if(x<y)cmmdc(y%x,x);else cmmdc(x%y,y);}  
int main()  
{int x,y,n;  
freopen("euclid2.in","r",stdin);freopen("euclid2.out","w",stdout);  
scanf("%d",&n);for(int loop=1;loop<=n;loop++){scanf("%d%d",&x,&y);cmmdc(x,y);}  
return 0;  
}  