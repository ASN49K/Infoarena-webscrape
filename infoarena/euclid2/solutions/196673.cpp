#include <iostream.h>
#include <fstream.h>

int cmmdc(int a, int b)
{if (a==0) return(b);
else
 if (b==0) return (a);
 else
  if (a>b)
   return(cmmdc(a%b,b));
     else
	 return(cmmdc(a,b%a));
}

int main(void)
{int n,x,y,i;
fstream f("euclid2.in",ios::in);
fstream g("euclid2.out",ios::out);
f>>n;
for (i=1;i<=n;i++)
{f>>x>>y;
 g<<cmmdc(x,y)<<endl;}
 f.close();g.close();
return(0);
}