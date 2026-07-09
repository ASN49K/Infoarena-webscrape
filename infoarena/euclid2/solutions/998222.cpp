#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int a,r,b,n,i;
int main()
{in>>n;
for(i=1;i<=n;i++)
{in>>a;
in>>b;
while(b!=0)
{r=a%b;
a=b;
b=r;
}
out<<a<<'\n';
}
}
