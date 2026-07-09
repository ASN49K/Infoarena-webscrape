#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int n,a,b,r;
    f>>n;
    for(int i=1;i<=n;i++)
    {

        f>>a>>b;
        r=a%b;
        while(r)
        {
            a=b;
            b=r;
            r=a%b;
        }
    g<<b<<"\n";
    }
    g.close();
    f.close();
    return 0;
}
