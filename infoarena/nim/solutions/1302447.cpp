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
            for (unsigned k=1;k<=nr[j];k++)
            {
                if (!prim)
                {
                    if (k%2==0) aldoilea++;
                        else primul++;
                }
                else if (k%2==1) aldoilea++;
                            else primul++;
                if (k==nr[j])
                    if (primul<aldoilea) prim=1;
                    else if (prim==aldoilea) prim=1;
                        else prim=0;
            }
        }
        if (primul<aldoilea) f1<<"NU";
        else f1<<"DA";
    }
    return 0;
}
