#include<fstream.h>   
unsigned long a,b,r;   
int main()   
{   
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>a>>b;   
while (b)   
{r=a%b;   
a=b;   
b=r;}   
if (a==1) g<<0;   
   else g<<a;   
f.close();   
g.close();   
return 0;   
}  