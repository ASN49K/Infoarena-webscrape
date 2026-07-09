#include <iostream>
#include <fstream>
using namespace std;
int main ()
{int a[100],b[100],r,i,t;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>t;
for(i=1;i<=t;i++)
{f>>a[i];
f>>b[i];}
for(i=1;i<=t;i++)
{do{r=a[i]%b[i];
a[i]=b[i];
b[i]=r;}while (b[i]>0);
 g<<a[i]<<endl;}
}
