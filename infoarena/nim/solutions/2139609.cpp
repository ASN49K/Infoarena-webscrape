#include <fstream>

using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int n,k,r,q,w;
int main()
{
    f>>n;
    for(int i=1; i<=n; i++)
    {
        f>>k;
        q=0;
        w=0;
        for(int j=1; j<=k; j++)
        {
            f>>r;
            if(q==0)
            {
                if(r==1)
                    w++;
            }
            if(r!=1)
                q=1;
        }
        if(k==1)
            g<<"DA"<<'\n';
        if(k>1)
        {
            if(w%2==0)
                g<<"DA"<<'\n';
            if(w%2==1)
                g<<"NU"<<'\n';
        }
    }
    return 0;
}
