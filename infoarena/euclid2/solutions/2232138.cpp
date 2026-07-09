#include <iostream>
#include <fstream>
using namespace std;
int t,a,b;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main()
{
    in>>t;

    for(int i=1;i<=t;i++)
    {
        in>>a>>b;int r=1;
        while(r>0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        out<<a<<'\n';
    }
    return 0;
}
