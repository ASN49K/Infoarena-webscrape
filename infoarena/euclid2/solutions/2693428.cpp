#include <iostream>
#include <fstream>
using namespace std;

int minim(int a,int b)
{
    return a>b ? a : b;
}

int main()
{
    fstream f("euclid2.in",fstream::in);
    fstream g("euclid2.out",fstream::out);

    int T,a,b;
    bool scris;
    f>>T;


    for(int i=T;i>0;i--)
    {
        scris=false;
        f>>a>>b;
        for(int j=minim(a,b);j>=2;j--)
        {
            if(a%j==0 && b%j==0)
            {
                scris=true;
                g<<j<<endl;
                break;
            }

        }
        if(scris==false)
            g<<1<<endl;
    }

    return 0;
}
