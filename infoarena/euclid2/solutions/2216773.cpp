#include <iostream>
#include <fstream>
using namespace std;
int a,b,r,n,i;
int main()
{
    ifstream f ("euclid2.in");
    ofstream g ("euclid2.out");
    f>>n;
    for(i=1;i<=n;i++)
    {f>>a>>b;


    do
    {
        r=a%b;
        a=b; b=r;
    }while (r!=0);
    g<<a<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
