#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,r,i,t;
int main()
{
    f>>t;
    for (i=1;i<=t;++i)
        {
            f>>a>>b;
            while(b!=0)
            {
                r=a%b;
                a=b;
                b=r;
            }
            g<<a<<'\n';
        }
        g.close();
        return 0;
}
