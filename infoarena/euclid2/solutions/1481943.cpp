#include <iostream>
#include<fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

short int t;
int a,b,r;

int main()
{ f>>t;
while(f>>a>>b)
{r=a%b;
while(r)
{
    a=b;
    b=r;
    r=a%b;
}
g<<b<<endl;
}
f.close();
g.close();
}
