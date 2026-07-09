#include<fstream>
#define NMAX 10005
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int i,n,q,el,s;
int main()
{
    f>>q;
    while(q)
    {
        q--;
        f>>n;
        s=0;
        for(i=1;i<=n;++i)
        {
            f>>el;
            s^=el;
        }
        if(s>0)
          g<<"DA\n";
        else
          g<<"NU\n";
    }
    return 0;
}
