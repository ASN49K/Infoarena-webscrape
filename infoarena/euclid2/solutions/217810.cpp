#include<fstream.h>   
ifstream f("euclid2.in");   
ofstream g("euclid2.in");   
long i,n,a,b;   
int main()   
{f>>n;   
for (i=1;i<=n;i++)   
{while (a!=b)   
if (a>b)   
a=a-b;   
else   
b=b-a;}   
g<<a;
g<<endl;   
f.close();   
g.close();   
return 0;}