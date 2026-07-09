#include <iostream>
#include <fstream>
using namespace std;


int a,b,n;
int cmmdc(int A,int B)
    {

        if (B==0) return A;
        else cmmdc(B,A%B);
    }

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
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
