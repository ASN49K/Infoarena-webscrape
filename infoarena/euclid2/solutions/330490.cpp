#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{long n,i,a,b,aux,rest;
f>>n;
for(i=1;i<=n;i++)
{f>>a;
f>>b;
if(b>a)
{aux=a;a=b;b=aux;}
rest=a%b;
while(rest!=0)
{a=b;b=rest;
rest=a%b;
}
g<<b<<endl;
}
f.close();
g.close();
return 0;
}