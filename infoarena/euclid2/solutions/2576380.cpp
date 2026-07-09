#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int N,A,B,R;
int main()
{
    f>>N;
    for(int i=1;i<=N;i++)
    {
        f>>A>>B;
        while(B)
        {
            R=A%B;
            A=B;
            B=R;
        }
        g<<A<<'\n';
    }
    return 0;
}
