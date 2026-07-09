#include <iostream>
#include <fstream>

using namespace std;

int n,a,b;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int euclid(int a,int b){
    if(!b) return a;
    return euclid(b,a%b);
}

int main()
{
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>a>>b;
        g<<euclid(a,b)<<"\n";
    }
    return 0;
}
