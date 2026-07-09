#include<fstream.h>
ifstream f("euclid.in");
ofstream g("euclid.out");
int main(void)
{
unsigned long int a,b,T,i;
f>>T;
for(i=1;i<=T;i++)
{
f>>a>>b;
while(a!=b)
{
if(a>b) a=a-b;
else b=b-a;
}
g<<a<<"\n";
}

return 0;
}
