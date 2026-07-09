#include <iostream>
#include<fstream>
using namespace std;
int euclid(long a,long b)
{int c;
    while(b)
{c=a%b;
a=b;
b=c;}
return a;

}
int main()
{ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,a,b;

f>>t;
for(int i=1;i<=t;i++)
{f>>a>>b;
g<<euclid(a,b)<<"\n";}

    return 0;
}
