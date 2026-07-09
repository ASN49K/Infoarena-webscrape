#include <fstream>
using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int main()
{
    int T,N,SUM;
    f>>T;
    while(T--)
    {
        f>>N;
        SUM=0;
        int x;
        for(;N--;f>>x,SUM^=x);
        if(SUM)
            g<<"DA\n";
        else
            g<<"NU\n";
    }
    return 0;
}
