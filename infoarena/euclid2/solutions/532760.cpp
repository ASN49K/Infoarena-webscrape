
#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{int i,n,a,b,aux;
f>>n;
for(i=0;i<n;i++)
f>>a>>b;
while(b)
{	aux=a%b;
    a=b;
	b=aux;
}
g<<b;
g.close();
f.close();
return 0;
}
