#include<cstdio>
int main()
{long a,b,r,i,t;
freopen("euclid2.in","rt",stdin);
freopen("euclid2.out","wt",stdout);
scanf("%ld\n",&t);
for(i=1;i<=t;i++)
      {scanf("%ld %ld\n",&a,&b);
      r=a%b;
      while(r!=0)
             {a=b;
             b=r;
             r=a%b;}
      printf("%ld\n",b);}
fclose(stdin);
fclose(stdout);
return 0;}
