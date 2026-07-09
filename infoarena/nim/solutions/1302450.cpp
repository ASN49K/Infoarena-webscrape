#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    #define NMAX 10001
    ifstream f("nim.in");
    ofstream f1("nim.out");
    unsigned t;
    f>>t;
    for (unsigned i=1;i<=t;i++)
    {
        unsigned long long n,nr[NMAX];
        bool prim=1;
        f>>n;
        unsigned long primul=0,aldoilea=0;
        for (unsigned j=1;j<=n;j++)
        {
            f>>nr[j];
            if (nr[j]%2==0)
            {
                if (prim) primul++;
                else aldoilea++;
            }
            else if (!prim) primul++;
                else aldoilea++;
        }
        if (primul<aldoilea) f1<<"NU\n";
        else f1<<"DA\n";
    }
    return 0;
}
