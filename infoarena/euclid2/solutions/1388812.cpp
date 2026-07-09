#include <fstream>

using namespace std;

int main()
{
    int a,b,r,i,t;
    ifstream f ("euclid2.in");
    ofstream g ("euclid2.out");
    f>>t;
    if(t<=32001 && t>=1)
    {
        for(i=1;i<=t;i++)
        {
            f>>a>>b;
            while(b!=0)
            {
                r=a%b;
                a=b;
                b=r;
            }
            g<<a<<"\n";
        }
        f.close();
        g.close();
    }
    return 0;
}
