#include<iostream>
#include<fstream>

using namespace std;

int euclid(int a,int b)
{
    if(!b)
        return a;
    euclid(b,a%b);
}

int main()
{
    int T,i,a,b,r;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>T;
    for(i=1;i<=T;i++)
    {
        f>>a>>b;
        g<<euclid(a,b);
    }
    f.close();
    g.close();
    return 0;
}
