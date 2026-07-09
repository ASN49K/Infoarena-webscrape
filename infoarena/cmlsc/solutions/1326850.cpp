#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int cmmdc(int a,int b)
{
while(a%b!=0)
    return cmmdc(b, a%b);
if(a%b==0)
    return b;
}

int main()
{int t,a,b;
ifstream f("euclid2.in");
FILE *g=fopen("euclid2.out","w");

f>>t;
while(t!=0)
    {
    f>>a>>b;
    fprintf(g,"%d\n",cmmdc(a,b));
    t--;
    }


return 0;
}
