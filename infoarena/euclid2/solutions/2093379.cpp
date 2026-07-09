#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");


int main()
{
    long N,A,B,r;

    f>>N;

    for(int i=0;i<N;i++)
    {
        f>>A>>B;
        while(B!=0)
            r=A%B,A=B,B=r;
        g<<A<<endl;
    }
    return 0;
}
