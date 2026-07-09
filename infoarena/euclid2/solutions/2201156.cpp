#include <iostream>
#include <fstream>
using namespace std;


ifstream f("euclid2.in");
ofstream g("euclid2.out");

int euclid(int a,int b)
{
    if(a==0) return b;
    if(b==0) return a;
    if(a!=0 && b!=0)
        return euclid(b,a%b);
}

int main()
{
    int a,b,n;
    f>>n;
    for(int i=1;i<=n;i++)

    {f>>a>>b;
    g<<euclid(a,b)<<endl;
    }
        return 0;
}
