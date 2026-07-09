#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmmdc.in");
ofstream g("cmmdc.out");
//cel mai mare divizor comun al nr a si b
//algortimul lui Euclid prin impartiri
int main()
{
    int a,b,r,n,i;
    f>>n;
    for(i=1;i<=n;i++)
    {f>>a>>b;
    while(b>0)
    {
        r=a%b;
        a=b;
        b=r;
    }
        g<<a<<'\n';}
    return 0;
}
