#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,i,a,b,t;

int main()
{
f>>n;
for(i=1;i<=n;i++)
{
    f>>a>>b;
    do
    {
        t=a%b;
        a=b;
        b=t;

    }while(t);
    g<<a<<endl;
}
    return 0;
}
