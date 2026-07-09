#include <fstream>

using namespace std;

int t,a,b;

int main()
{
    ifstream in ("euclid2.in");
    ofstream out ("euclid2.out");

    in>>t;
    for (;t>0;--t)
    {
        in>>a>>b;
        while (b!=0)
        {
            int v=a;
            a=b;
            b=v%b;
        }
        out<<a<<"\n";
    }

    in.close();
    out.close();
    return 0;
}
