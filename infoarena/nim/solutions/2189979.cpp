#include <fstream>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

long long int x,sum;
int t,j,n,i;

int main()
{
    f>>t;
    for(i=1; i<=t; i++) {
        f>>n;

        for(j=1; j<=n; j++) {
            f>>x;
            if(j==1)
                sum=x;
            else sum=sum^x;
        }

        if(sum==0)
            g<<"NU";
        else g<<"DA";
        g<<'\n';

    }
    return 0;
}
