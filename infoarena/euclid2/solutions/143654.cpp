#include<stdio.h>
long a,b,r;
long eb(long a,long b)
    {
      long k,dif;
      //1. Cazurile speciale cu 0
      if ((a==0)||(b==0))
	      return(a|b);
      //2.Determinam cea mai mare putere a lui 2 care apare in a si b
      for(k=0;((a|b)&1)==0;++k)
      {a>>=1;//a=a/2
       b>>=1;//b=b/2
      }
      //3.a-->impar
      while((a&1)==0) a>>=1;
      //4.alg. principal
      do
      { while((b&1)==0) b>>=1;
	//a si b sunt impare
	if(b>a) b=b-a;
	   else {dif=a-b; a=b; b=dif;}
      }while(b);
      return a<<k ;
    }

int main()
{
 freopen("euclid2.in","r",stdin);
 freopen("euclid2.out","w",stdout);
 scanf("%ld%ld",&a,&b);
 a=eb(a,b);
 printf("%ld",a);
 return 0;
}