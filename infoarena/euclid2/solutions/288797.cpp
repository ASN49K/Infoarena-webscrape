#include<fstream.h>
ifstream f("cmmdc.in");
ofstream g("cmmdc.out");
long a,b;
int main()
{f>>a>>b;
while (a!=b)
if (a>b)
a=a-b;
else
b=b-a;
if (a==1)
g<<0;
else
g<<a;
f.close();
g.close();
return 0;}