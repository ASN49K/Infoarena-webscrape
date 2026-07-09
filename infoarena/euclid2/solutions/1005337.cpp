#include <fstream>
using namespace std;

int a,b,n,i,r1,r2,d;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a;f>>b;
        if(a<b)
            swap(a,b);
        r1=b;d=a;r2=1;
        while(r2!=0)
        {
            r2=d%r1;
            if(r2==0)
                g<<r1<<"\n";
            else
            {
                r1=r2;d=r1;
            }
        }
    }
    f.close();g.close();
    return 0;
}
