#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main()
{
    int n,g,b;
    in>>n;
    for(int i=1;i<=n;i++)
    {
        in>>g>>b;
        int r=g%b;
        while(r>0)
        {
            g=b;
            b=r;
            r=g%b;
        }
        out<<b<<"\n";
    }
    return 0;
}
