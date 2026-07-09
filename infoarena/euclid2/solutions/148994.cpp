#include<fstream.h>   
long long a,b,r;   
int main()
{   
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>a>>b;
if (a==0&&b==0) g<<"0";
    else if (a!=0&&b==0) g<<a;
    else
{while (b)
{r=a%b;
a=b;
b=r;}
if (a==1) g<<"0";
   else g<<a;}
f.close();
g.close();
return 0;
}