#include <fstream>
 
using namespace std;
 
int t, n, a, xorsum;
 
int main()
{
    ifstream in("nim.in");
    ofstream out("nim.out");
 
    in>>t;
 
    while(t--)
    {
        in>>n;
 
        xorsum = 0;
        for(int i = 1; i <= n; ++i)
        {
            in>>a;
            xorsum = xorsum ^ a;
        }
 
        if(xorsum)
            out<<"DA\n";
        else
            out<<"NU\n";
    }
 
    return 0;
}
