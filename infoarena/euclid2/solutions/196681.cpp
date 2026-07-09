#include <iostream>
#include <fstream>

int cmmdc(int a, int b)
{if (b==0) return(a);
return(cmmdc(b,a%b));
}

int main(void)
{int n,x,y;
fstream f("euclid2.in",ios::in);
fstream g("euclid2.out",ios::out);
f>>n;
for (;n;--n)
{f>>x>>y;
 g<<cmmdc(x,y)<<endl;}
 f.close();g.close();
return(0);
}