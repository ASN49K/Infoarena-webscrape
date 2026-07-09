#include <iostream>
#include <fstream>
using namespace std;
int main ()
{int a,b,r,i,t;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>t;
for(i=1;i<=t;i++)
{f>>a;
f>>b;}
for(i=1;i<=t;i++)
{do{r=a%b;
a=b;
b=r;}while (b>0);
if(a==1) g<<0;
else g<<a;}
}
