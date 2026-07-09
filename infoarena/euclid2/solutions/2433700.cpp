#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main()
{
    int n,i,a,b,k;

    ifstream f ("euclid2.in");
    ofstream g ("euclid2.out");
    f>>n;

    for(i=0;i<n;i++)
     {

        f>>a>>b;
        if(a<b) swap(a,b);
        k=a - (a/b)*b;
        while(k)
        {
            a=b;
            b=k;
            k=a - (a/b)*b;
        }
        g<<b<<endl;}
    return 0;
}
