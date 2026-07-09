#include<fstream.h>
unsigned long a,b,r,t;

int main()
{ifstream f("euclid2.in");
ofstream g("euclid2.out");
for(int i=1;i<t+1;i++){f>>a>>b;
while(b)
{r=a%b;
 a=b;b=r;}

g<<a;}f.close();
g.close();

return 0;}