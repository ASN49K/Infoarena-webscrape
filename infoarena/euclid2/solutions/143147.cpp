#include<fstream.h>
unsigned long a,b,r;

int main()
{ifstream f("euclid2.in");
f>>a>>b;f.close();
while(b)
{r=a%b;
 a=b;b=r;}
ofstream g("euclid2.out");
g<<a;
g.close();

return 0;}