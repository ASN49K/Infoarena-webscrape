#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int t,a,b;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    do
    {
        f>>a>>b;
        if (a%b==0) g<<b<<"\n";
        else
        {
            while (a%b!=0)
            {
                a=a%b;
                b=b%a;
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
