#include<iostream>
#include<fstream>
using namespace std;
int main()
{

    long a,b,r,i, n;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        r=a%b;
        while(r!=0)
        {
            a=b;
            b=r;
            r=a%b;
        }
        g<<b<<endl;
    }
    g.close();
    f.close();
    return 0;
}
