# include <stdio.h>

# define FIN "euclid2.in"
# define FOUT "euclid2.out"

int a,b,n,i;

    int cmmdc(int a, int b)
    {
        if (!a) return b;
           else return cmmdc(b%a,a);
    }

     int main()
     {
        freopen(FIN,"r",stdin);
        freopen(FOUT,"w",stdout);
        
        scanf("%d",&n);
        
        for (i=1; i<=n; i++)
          {
             scanf("%d %d",&a,&b);
             printf("%d\n",cmmdc(a,b));
          }
          
        return 0;
     }
