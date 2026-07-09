#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    long int t,a,b,q;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    do
    {
        f>>a>>b;
        if (b==0)
        {
            b=a;
        }
        if (a%b==0) g<<b<<"\n";
        else
        {
            q=a%b;
            while (a%b)
            {
                a=b;
                b=q;
                q=a%b;
            }
            g<<b<<"\n";
        }
        t--;
    }
    while (t!=0);
    f.close();
    g.close();
    return 0;
}
