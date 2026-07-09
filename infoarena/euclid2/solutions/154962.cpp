#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long a,b,r,t;

void eu()
{f>>a>>b;
while(b)
{r=a%b;
a=b;
b=r;
}
g<<a<<'\n';
}
int main()
{f>>t;
for(long i=1;i<=t;i++)
 eu();
f.close();
g.close();
return 0;
}
