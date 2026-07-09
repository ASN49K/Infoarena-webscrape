#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a, int b)
{
    if(a==0||b==0)
    {
        if(a>b)
            return a;
        else
            return b;
    }
    int r=a%b;
    while(r!=0)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int main()
{
    int t,i,x,y;
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>x>>y;
        g<<cmmdc(x,y)<<'\n';
    }
    return 0;
}
