#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
unsigned long int a,b,r;
int i,n;
int main()
{
    f>>n;
    for(i=0;i<n;i++)
        {
            f>>a>>b;
            r=a%b;
            while(r!=0)
                {
                    a=b;
                    b=r;
                    r=a%b;
                }
            g<<b<<'\n';
        }
    f.close();
    g.close();
}
