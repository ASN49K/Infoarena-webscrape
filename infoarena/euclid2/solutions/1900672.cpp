#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,i,x,y,a,b,r;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>x>>y;
        a=x;
        b=y;
        r=a%b;
        if(r==0)
        g<<y<<"\n";
        else
        {
        while(r!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        g<<a<<"\n";
        }
    }
    return 0;
}
