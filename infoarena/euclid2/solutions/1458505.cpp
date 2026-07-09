#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(int A,int B)
    {
        if (A%B==0) return B;
        else cmmdc(B,B%A);
    }

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    int a,b,n;
    f>>n;
    for (int i=1;i<=n;i++)
    {
    f>>a>>b;
    g<<cmmdc(a,b)<<"\n";
    }
   f.close();
   g.close();
    return 0;
}
