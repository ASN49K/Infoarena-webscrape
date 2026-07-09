#include <iostream>
#include <fstream>
using namespace std;
int cmmdc(int x,int y)
{
    int r=x%y;
    while (r!=0)
    {
        x=y;
        y=r;
        r=x%y;
    }
    return y;
}
int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int i,n,x,y;
    in>>n;
    for (i=1;i<=n;i++)
    {
        in>>x>>y;
        out<<cmmdc(x,y)<<"\n";
    }
}
