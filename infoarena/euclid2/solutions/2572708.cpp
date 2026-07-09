#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int t, a, b;

int cmmdc()
{
    while(b!=0)
    {
        int r=a%b;
        a=b;
        b=r;
    }

    return a;
}

int main()
{
    in>>t;

    while(t--)
    {
        in>>a>>b;
        out<<cmmdc()<<'\n';
    }


    in.close();
    out.close();
    return 0;
}
