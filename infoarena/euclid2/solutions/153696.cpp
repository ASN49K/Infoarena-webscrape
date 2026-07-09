#include<fstream.h>
long long a,b,r,t,i;

int main()
{ifstream f("euclid2.in");
 ofstream g("euclid2.out");
 f>>t;
 for(i=1;i<t+1;i++)
{f>>a>>b;
while(b)
{r=a%b;
 a=b;b=r;}
g<<a<<"\n";}

f.close();
g.close();

return 0;}