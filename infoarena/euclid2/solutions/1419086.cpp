#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int t,a,b,i;
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>a>>b;
        while(a!=b)
        {
            if(a>b)
                a-=b;
            else b-=a;
        }
        g<<a<<endl;
    }
    f.close();
    g.close();
    return 0;
}
