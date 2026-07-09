#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");

long euclid(long a,long b)
{
  long r;
  r=a%b;
 while(r!=0)
  {a=b;
   b=r;
   r=a%b;
   }

 return b;
}



void cit()
{

 long t,a,b;
   f>>t;
 for(register long i=1;i<=t;i++)
  {f>>a>>b;
  g<<euclid(a,b)<<'\n';    }


}

int main()
{

 cit();
return 0;
}