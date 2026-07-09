#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int a,b,a1,b1,i,n,c;
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        a1=a;
        b1=b;
        while(b1)
        {
            c=a1%b1;
            a1=b1;
            b1=c;
        }
        g<<c<<" "<<endl;
    }
    return 0;
}
