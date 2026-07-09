#include<iostream.h>
#include<stdio.h>
using namespace std;

int cmmdc (int a, int b)
{
while(a!=0 && b!=0)	
{  if(a>b) a=a%b;
  else b=b%a;}

return a+b; 
}

int main()
{ int a,b,t,i;

freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);

scanf("%d",&t);

for(i=1;i<=t;i++)
{    scanf("%d",&a);
     scanf("%d",&b); 
     printf("%d\n",cmmdc(a,b));
}



}
