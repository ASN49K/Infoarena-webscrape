#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main()
{
    int t,a,b,r;

    in>>t;
    for(int i=1; i<=t; i++)
    {
        in>>a>>b;
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        out<<a<<'\n';
    }

    return 0;
}
