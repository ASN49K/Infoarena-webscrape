#include <fstream>
#define int long long
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int t,a,b,c;
int euclid(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int xx,yy;
    int ceva=euclid(b,a%b,xx,yy);
    x=yy;
    y=xx-a/b*yy;
    return ceva;
}
main()
{
    in>>t;
    while(t--)
    {
        in>>a>>b;
        int x,y;
        int cmmdc=euclid(a,b,x,y);
        out<<cmmdc<<'\n';
    }
    return 0;
}
