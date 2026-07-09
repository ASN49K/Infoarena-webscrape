# include <stdio.h>

# define FIN "euclid2.in"
# define FOUT "euclid2.out"

long a,b,n,i;

long cmmdc(long a, long b)
{
 if (b==0) return a;
      else return cmmdc(b, a%b);
}

int main()
{
 freopen(FIN,"r",stdin);
 freopen(FOUT,"w",stdout);
 scanf("%ld",&n);
 for (i=1; i<=n; i++)
   {
    scanf("%ld %ld",&a,&b);
    printf("%ld\n",cmmdc(a,b));
   }
 return 0;
}
