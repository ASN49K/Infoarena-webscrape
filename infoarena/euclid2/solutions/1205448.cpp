#include <iostream>
#include<fstream>

using namespace std;

int main()
{int n,a,b,c;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>a>>b;
        while(b)
        {
            c=a%b;
            a=b;
            b=c;
        }
        g<<a<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
