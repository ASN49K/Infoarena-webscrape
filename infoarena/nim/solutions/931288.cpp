#include <fstream>
#define In "nim.in"
#define Out "nim.out"
using namespace std;

int main()
{
    int T,N,x,sum,i;
    ifstream f(In);
    ofstream g(Out);
    f>>T;
    while(T--)
    {
        f>>N;
        sum = 0;
        for(i=1;i<=N;i++)
        {
            f>>x;
            sum ^=x;
        }
        if(sum)
            g<<"DA\n";
        else
            g<<"NU\n";
    }
    f.close();
    g.close();
    return 0;
}
