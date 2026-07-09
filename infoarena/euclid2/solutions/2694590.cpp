#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int T,A,B,R;
int main()
{
    f>>T;
    for(int i=0; i<T; i++)
    {
        f>>A>>B;
        while(B!=0)
        {
            R=A%B;
            A=B;
            B=R;
        }
        g<<A<<'\n';
    }
    return 0;
}
