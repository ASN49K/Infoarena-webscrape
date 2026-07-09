#include <fstream>
#include <iostream>
using namespace std;
fstream in("euclid2.in", ios::in);
fstream out("euclid2.out", ios::out);
int euclid(int a,int b)
{
    if (a%b==0)
        return b;
     return euclid(b, a%b);
}
int main()
{
    int a,b,n,i,aux=0;
    in>>n;
    for (i=1;i<=n;i++)
    {
        in>>a>>b;
        aux=euclid(a,b);
        out<<aux<<'\n';
    }
    in.close();
    out.close();
}

