#include <cstdio>
#define infile "euclid2.in"
#define outfile "euclid2.out"

long long a,b;
int T;

void euclid()
{
      long long r=a%b;

      while(r>0)
      {
            a=b;
            b=r;
            r=a%b;
      }

      printf("%lld\n",b);
}

int main()
{
      freopen(infile,"r",stdin);
      freopen(outfile,"w",stdout);

      scanf("%d",&T);
      for(;T;T--)
      {
            scanf("%lld%lld",&a,&b);
            euclid();
      }

      fclose(stdin);
      fclose(stdout);
      return 0;
}
