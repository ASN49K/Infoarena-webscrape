#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int T,A,B,R;
int main()
{
    f>>T;
    for(;T;--T)
    {
        f>>A>>B;
        do
        {
            R=A%B;
            A=B;
            B=R;
        }
        while(R);
        g<<A<<"\n";
    }
}
