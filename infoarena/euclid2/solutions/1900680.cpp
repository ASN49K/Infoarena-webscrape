#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,i,a,b,x,y,r;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        x=a;
        y=b;
        r=x%y;
        if(r==0) g<<y<<"\n";
        else
        {
            while(r!=0)
            {
                r=x%y;
                x=y;
                y=r;
            }
            g<<x<<"\n";
        }
    }
    return 0;
}
