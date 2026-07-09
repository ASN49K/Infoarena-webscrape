#include<fstream.h>
fstream f,g;
long int i,a,b,T;
void main()
{f.open("euclid2.in",ios::in);
g.open("euclid2.out",ios::out);
f>>T;
for(i=1;i<=T;i++)
{f>>a>>b;
while(a!=b)
{if(a>b)
a=a-b;
else
b=b-a;}
g<<a<<endl;
}
f.close();
g.close();
}