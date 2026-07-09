#include <fstream>
#include <cstring>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
char w[1000];
int v[1000];
int main()
{
    int n,i,x,y,r;
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>x>>y;
        r=1;
        while(r!=0)
        {
            if(x>y)
            {
                r=x%y;
                x=r;
            }
            else
            {
                r=y%x;
                y=r;
            }
        }
        if(x<y)
        g<<y<<endl;
        else
            g<<x<<endl;
    }

    return 0;
}
