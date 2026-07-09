#include <iostream>

#include <fstream>

using namespace std;

int main()
{ifstream in ("euclid2.in");
ofstream out ("euclid2.out");
int n,i,a,b,r;
in>>a>>b;
in>>n;
for(i=1;i<=n;i++)
{r=a%b;
while (r!=0)
{
    a=b;
    b=r;
    r=a%b;
}
out<<b<<endl;}
    return 0;
}
