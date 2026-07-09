#include <fstream>
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int main()
{int t, n, aux,sum=0;
f>>t;
    for(int i=0;i<t;i++)
        {
            f>>n;
            for(int j=0;j<n;j++)
            {
                f>>aux;
                sum^=aux;
            }
            if(sum) g<<"DA"<<'\n'; else g<<"NU"<<'\n';
        }

    return 0;
}
