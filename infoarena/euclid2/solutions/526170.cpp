#include <iostream>
#include <fstream>
using namespace std;

int cmmdc (int a,int b)
{int aux;
while (b!=0) {aux=a%b;
              a=b;
              b=aux;}
return a;
}

int main (void)

{
fstream f("euclid2.in",ios::in);
fstream g("euclid2.out",ios::out);

int T,a,b,i;
f>>T;
for (i=1;i<=T;i++)
    {f>>a>>b;
	 g<<cmmdc(a,b)<<"\n";}
g.close();
return 0;
}
