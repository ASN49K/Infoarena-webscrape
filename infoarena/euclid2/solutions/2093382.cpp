#include <fstream>
#include <stdio.h>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

long Euclid(long a,long b)
{
    if(b==0) return a;
    return Euclid(b,a%b);
}

int main()
{
    long N,A,B,r;

    f>>N;

    for(int i=0;i<N;i++)
    {
        f>>A>>B;
        g<<Euclid(A,B)<<endl;
    }
    return 0;
}
