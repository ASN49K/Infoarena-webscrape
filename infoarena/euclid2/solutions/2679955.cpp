#include <iostream>
#include <fstream>
using namespace std;
int T, i , el1, el2, a, b;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    f>>T;
    for(i=1;i<=T;i++)
    {
        f>>a;
        f>>b;
        el1=a;
        el2=b;
        while (el1!=el2)
        {
            if(el1>el2)
                el1=el1-el2;
            else
                el2=el2-el1;
        }
      g<<el1;
      g<<endl;
    }
    f.close( );
    g.close( );

    return 0;
}
