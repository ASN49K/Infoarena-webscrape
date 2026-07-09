#include<stdio.h>
int n,t,a,l;
int main()
{freopen("nim.in","r",stdin);
freopen("nim.out","w",stdout);
scanf("%d",&t);
while(t--)
       {scanf("%d",&n);
       l=0;
       while(n--)
               scanf("%d",&a),l^=a;
       if(!l)
               printf("NU\n");
       else
               printf("DA\n");}
return 0;}
