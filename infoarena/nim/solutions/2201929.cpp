#include <fstream>

using namespace std;
ifstream fi("nim.in");
ofstream fo("nim.out");
int t, n, x, sxor;

int main()
{
    fi>>t;
    while(t--)
    {
        fi>>n;
        fi>>x;
        sxor=x;
        for(int i=2; i<=n; i++)
        {
            fi>>x;
            sxor^=x;
        }
        if(sxor)
            fo<<"DA\n";
        else
            fo<<"NU\n";
    }
    fi.close();
    fo.close();
    return 0;
}
