#include<stdio.h>
 using namespace std;
int cmmdc(int a,int b)
{
 if(b==0)return a;
 else return cmmdc(b,a%b);
}
int main()
{
int a,b,c;
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","r",stdout);
scanf("%d",&c);
while(c--)
{
scanf("%i %i",&a,&b);
if(a>b)printf("%i",cmmdc(a,b));
else printf("%i\n",cmmdc(b,a));
}
return 0;
}
