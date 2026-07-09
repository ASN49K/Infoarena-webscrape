#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int euclid(int a,int b)
{
    int s;
    while(b)
    {
        s=b;
        b=a%b;
        a=s;
    }
    return a;
}
int main()
{
    int t,x,y;
    f>>t;
    for(int i=1; i<=t; ++i)
    {
        f>>x>>y;
        g<<euclid(x,y)<<endl;
    }
    g<<endl;
    return 0;
}
