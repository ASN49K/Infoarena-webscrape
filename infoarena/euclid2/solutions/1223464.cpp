#include <fstream>

using namespace std;
int t, a ,b,i;

int cmmdc(int a, int b)
{
    int c;
    while (b>0)
    {   c=b;
        b=a%b;
        a=c; }
    return a;
}

int main()
{
    ifstream f1("euclid2.in");
    ofstream f2("euclid2.out");
    f1>>t;
    for (i=1; i<=t; i++)
    { f1>>a>>b;
      f2<<cmmdc(a,b)<<"\n"; }

    f1.close();
    f2.close();
    return 0;
}
