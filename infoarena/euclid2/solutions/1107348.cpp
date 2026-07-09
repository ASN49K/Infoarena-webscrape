#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int t, i, k=1, x, y, r;
    ifstream a("euclid2.in");
    ofstream b("euclid2.out");
    a>>t;
    int v[2*t+1];
    for (i=1; i<=2*t; i++)
        a>>v[i];
    while (k<=2*t-1)
    {
        x=v[k]; y=v[k+1];
        do
        {
            r=x%y;
            x=y;
            y=r;
        }
        while (r!=0);
        b<<x<<endl;
        k=k+2;
    }
    a.close(); b.close();
    return 0;
}
