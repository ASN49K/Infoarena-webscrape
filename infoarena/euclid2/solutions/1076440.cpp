#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int euclid(int x,int y)
{
    if(!y) return x;
    else
    {
        return euclid(y,x%y);
    }
}
int main()
{
    int a,b,n;
    in>>n;
    for(int i=1;i<=n;i++)
    {
        in>>a>>b;
        out<<euclid(a,b)<<'\n';
    }
}
