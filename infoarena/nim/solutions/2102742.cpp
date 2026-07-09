#include <fstream>

using namespace std;
ifstream fi("nim.in");
ofstream fo("nim.out");
int t,n,x,xorr;
int main()
{
    fi>>t;
    while(t--)
    {
        fi>>n;
        xorr=0;
        for(int i=1;i<=n;i++)
        {
            fi>>x;
            xorr=xorr^x;
        }
        if(xorr)
            fo<<"DA\n";
        else
            fo<<"NU\n";
    }
    fi.close();
    fo.close();
    return 0;
}
