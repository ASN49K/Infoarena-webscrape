#include <fstream>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int cmmdc(int n,int m)
{
    int x;
    while(m!=0)
    {
        x=n%m;
        n=m;
        m=x;
    }
    return n;
}
int main()
{
    int n,i,x,y;
    in>>n;
    for(i=1;i<=n;i++)
    {
        in>>x>>y;
        out<<cmmdc(x,y)<<'\n';
    }
    return 0;
}
