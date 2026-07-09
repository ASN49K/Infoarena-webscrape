#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int T,i,a,b;
    ifstream f("euclid.in");
    ofstream g("euclid.out");
    f>>T;
    for(i=1;i<=T;i++)
    {
        f>>a;
        f>>b;
        while(a!=b)
        if(a>b)
        a=a-b;
        else
        b=b-a;
        g<<b<<endl;
    }
    f.close();
    g.close();
    return 0;
}
