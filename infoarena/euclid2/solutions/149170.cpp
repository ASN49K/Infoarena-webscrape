#include<fstream.h>


int main()
{ifstream f("euclid2.in");
long a,b,r;
f>>a>>b;
f.close();
while(b)
{r=a%b;
a=b;
b=r;
}
ofstream g("euclid2.out");
g<<a<<'\n';
g.close();
return 0;
}